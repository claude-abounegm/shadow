package shadow.typecheck;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import org.apache.commons.logging.Log;

import shadow.Loggers;
import shadow.AST.ASTUtils;
import shadow.AST.ASTWalker.WalkType;
import shadow.AST.AbstractASTVisitor;
import shadow.parser.javacc.Node;
import shadow.parser.javacc.SimpleNode;
import shadow.typecheck.type.ClassInterfaceBaseType;
import shadow.typecheck.type.MethodType;
import shadow.typecheck.type.ModifiedType;
import shadow.typecheck.type.SequenceType;
import shadow.typecheck.type.Type;
import shadow.typecheck.type.TypeParameter;

public abstract class BaseChecker extends AbstractASTVisitor {
	
	private static final Log logger = Loggers.TYPE_CHECKER;

	protected ArrayList<String> errorList = new ArrayList<String>();;
	protected HashMap<Package, HashMap<String, ClassInterfaceBaseType>> typeTable; /** Holds all of the types we know about */
	protected List<File> importList; /** Holds all of the imports we know about */
	protected Package packageTree;	
	protected Package currentPackage;
	protected LinkedList<Node> currentMethod = new LinkedList<Node>();  /** Current method is a stack since Shadow allows methods to be defined inside of methods */
	

	/** Holds the package tree structure (for name lookups) */
	protected ClassInterfaceBaseType currentType = null;
	protected boolean debug;	
	
	// these are constants for our error messages to keep things consistent
	// TODO: Add more of these
	public static enum Error {
		INVL_TYP		{ public String toString()  { return "INVALID TYPE"; } },
		MULT_SYM		{ public String toString()  { return "MULTIPLY DEFINED SYMBOL"; } },
		MULT_MTH		{ public String toString()  { return "MULTIPLY DEFINED METHODS"; } },
		UNDEC_VAR		{ public String toString()  { return "UNDECLARED VARIABLE"; } },
		UNDEF_TYP		{ public String toString()  { return "UNDEFINED TYPE"; } },
		TYPE_MIS		{ public String toString()  { return "TYPE MISMATCH"; } },
		INVL_MOD		{ public String toString() { return "INVALID MODIFIER"; } };
		
		//abstract String getStr();
	}
	
	public final HashMap<Package, HashMap<String, ClassInterfaceBaseType>> getTypeTable() {
		return typeTable;
	}
	
	public void addType( ClassInterfaceBaseType type  ) {		
		addType( type, packageTree );
	}
	
	public void addType( ClassInterfaceBaseType type, Package p  ) {
		p.addType(type); //automatically adds to typeTable and sets type's package				
	}
	
	public final List<File> getImportList() {
		return importList;
	}
	
	public BaseChecker(boolean debug, HashMap<Package, HashMap<String, ClassInterfaceBaseType>> hashMap, List<File> importList, Package packageTree  ) {
		this.debug = debug;
		this.typeTable = hashMap;
		this.importList = importList;
		this.packageTree = packageTree;
	}
	
	protected Object pushUpType(SimpleNode node, Boolean secondVisit) {
		return pushUpType(node, secondVisit, 0);
	}
	
	protected Object pushUpType(SimpleNode node, Boolean secondVisit, int child) {
		if(secondVisit)
		{
			if( node.jjtGetNumChildren() > child )
			{			
				// simply push the type up the tree
				Node childNode = node.jjtGetChild(child); 
				node.setType(childNode.getType());
				node.setModifiers( childNode.getModifiers());
			}
		}
		
		return WalkType.POST_CHILDREN;
	}
	
	protected void pushUpModifiers( SimpleNode node ) //only pushes up modifiers if there is a single child
	{
		if( node.jjtGetNumChildren() == 1 )
		{
			Node child = node.jjtGetChild(0);
			node.setModifiers( child.getModifiers() );
		}
	}
	
	
	

	/**
	 * Adds an error message to the list errors we keep until the end.
	 * @param node The node where the error occurred. This will be printed in the standard format.
	 * @param msg The message to communicate to the user.
	 */
	protected void addError(Node node, String msg) {
		addError( node, null, msg );
	}
	
	/**
	 * Adds an error messages to the list of errors.
	 * @param node The node where the error occurred. This will be printed in standard format.
	 * @param type One of the pre-defined types of errors.
	 * @param msg The message associated with the error.
	 */
	protected void addError(Node node, Error type, String msg) {
		String error = "";
		
		if( node != null )
		{
			if( node.getFile() != null )
				error += "(" + node.getFile().getName() + ")";
			error += "[" + ASTUtils.getLineCol(node) + "] ";
		}
		
		if( type != null )
			error += type;
		
		if( msg != null && msg.length() > 0 )
			error += ": " + msg; 
		
		errorList.add(error);
	}
	
	/**
	 * Adds an error messages to the list of errors.
	 * @param node The node where the error occurred. This will be printed in standard format.
	 * @param type One of the pre-defined types of errors.
	 */
	protected void addError(Node node, Error type) {
		addError( node, type, "" );
	}
	
	protected void addError(Error type, String message) {
		addError( null, type, message );
	}
	
	
	/**
	 * Print out the list of errors to the given stream.
	 * @param stream The stream to print the errors to.
	 */
	public void printErrors() {
		for(String msg:errorList) {
			logger.error(msg);
		}
	}
	
	
	public final ClassInterfaceBaseType lookupTypeFromCurrentMethod( String name )
	{		
		for( Node method : currentMethod )
		{
			MethodType methodType = (MethodType)(method.getType());
			if( methodType.isParameterized() )
			{
				for( ModifiedType modifiedType : methodType.getTypeParameters() )
				{
					Type type = modifiedType.getType();
					if( type instanceof TypeParameter )
					{
						TypeParameter typeParameter = (TypeParameter) type;
						
						if( typeParameter.getTypeName().equals(name))
							return typeParameter;
					}
				}
			}			
		}
		
		return lookupTypeStartingAt( name, currentType );
	}
	
	//outer class is just a guess, not a sure thing
	//this method is used when starting from a specific point (as in when looking up extends lists), rather than from the current type
	public final ClassInterfaceBaseType lookupTypeStartingAt( String name, Type outer )
	{	
		ClassInterfaceBaseType type = null;
		
		if( name.contains("@"))
		{
			int atSign = name.indexOf('@');
			return lookupType( name.substring(0, atSign), name.substring(atSign + 1 ) );
		}
		else if( outer != null ) 		//try starting points
		{			
			type = lookupType( name, outer );
			if( type != null )
				return type;
			
			//check type parameters of outer class
			if( outer.isParameterized() )
				for( ModifiedType modifiedParameter : outer.getTypeParameters() )
				{
					Type parameter = modifiedParameter.getType();
					
					if( parameter instanceof TypeParameter )
					{
						TypeParameter typeParameter = (TypeParameter) parameter;
						if( typeParameter.getTypeName().equals(name) )
							return typeParameter;
					}
				}
		
			//walk up packages from there
			Package p = outer.getPackage();		
			while( p != null)
			{
				type = lookupType( name, p  );
				if( type != null )
					return type;			
				
				p = p.getParent();
			}			
		}
		
		//still not found, try all packages
		for( Package _package : typeTable.keySet() )
		{
			type = lookupType( name, _package  );
			if( type != null )
				return type;			
		}
		
		return null;	
	}
	
	//nothing known, start with current method (looking for type parameters)
	public ClassInterfaceBaseType lookupType( String name )
	{
		if( name.contains("@"))
		{
			int atSign = name.indexOf('@');
			return lookupType( name.substring(0, atSign), name.substring(atSign + 1 ) );
		}
		else
			return lookupTypeFromCurrentMethod( name );
	}
		
	//outer class known, no need to look at packages
	public final ClassInterfaceBaseType lookupType( String name, Type outerClass )
	{			
		Package p = outerClass.getPackage();
		
		if( p == null )
			p = packageTree;
		
		Map<String, ClassInterfaceBaseType> types = typeTable.get(p);
		
		String prefix = outerClass.getTypeName();		
		
		while( !prefix.isEmpty())
		{
			if( types.containsKey(prefix + "." + name))
				return types.get(prefix + "." + name);
			
			if( prefix.contains("."))
				prefix = prefix.substring(0, prefix.lastIndexOf('.'));
			else
				prefix = "";
		}
		
		return types.get(name);
	}
	
	//get type from specific package
	public final ClassInterfaceBaseType lookupType( String name, Package p )
	{		
		return typeTable.get(p).get(name);
	}
	
	public final ClassInterfaceBaseType lookupType( String packageName, String name )
	{			
		Package p;
		
		if( packageName.equals("default") )
			p = packageTree;
		else
			p = packageTree.getChild(packageName);
		
		if( p == null )
		{
			addError(Error.UNDEF_TYP, "Package " + packageName + " not defined");
			return null;
		}
		
		HashMap<String, ClassInterfaceBaseType> map = typeTable.get(p); 
		return map.get(name);
	}
	
	public int getErrorCount() {
		return errorList.size();
	}
	
	public Package getPackageTree()
	{
		return packageTree;
	}
	

	
	
	//All must work
	//class LinkedList<T is Eggplant> implements List<T>
	//class LinkedList<T, U is T> implements List<T>
	//class Piglet implements LinkedList<Pig>
	/*
	protected boolean checkTypeArguments( List<Type> parameters, SequenceType arguments )
	{
		if( parameters.size() != arguments.size() )
			return false;
		
		for( int i = 0; i < parameters.size(); i++ )
		{
			if( parameters.get(i) instanceof TypeParameter  )
			{			
				TypeParameter parameter = (TypeParameter) parameters.get(i);
				if( !parameter.canAccept( arguments.get(i)  ) )
						return false;
			}
			else
				return false;
		}	
		
		return true;
	}
	*/
	
}
