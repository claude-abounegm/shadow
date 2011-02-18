/**
 * 
 */
package shadow.output.C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

import shadow.TAC.TACClass;
import shadow.TAC.TACMethod;
import shadow.TAC.TACVariable;
import shadow.TAC.nodes.TACAllocation;
import shadow.TAC.nodes.TACAssign;
import shadow.TAC.nodes.TACBinaryOperation;
import shadow.TAC.nodes.TACBranch;
import shadow.TAC.nodes.TACJoin;
import shadow.TAC.nodes.TACLoop;
import shadow.TAC.nodes.TACMethodCall;
import shadow.TAC.nodes.TACNoOp;
import shadow.TAC.nodes.TACNode;
import shadow.TAC.nodes.TACReturn;
import shadow.TAC.nodes.TACUnaryOperation;
import shadow.output.AbstractTACLinearVisitor;
import shadow.parser.javacc.Node;
import shadow.parser.javacc.ShadowException;
import shadow.parser.javacc.ShadowParser.ModifierSet;
import shadow.typecheck.type.ModifiedType;
import shadow.typecheck.type.Type;

/**
 * @author wspeirs
 *
 */
public class TACCVisitor extends AbstractTACLinearVisitor {

	private CPrettyPrinter cWriter;
	private CPrettyPrinter metaWriter;
	private CPrettyPrinter curWriter;
	
	private String cFileName = null;
	private String metaFileName = null;

	/**
	 * @param root
	 */
	public TACCVisitor(TACClass theClass) {
		super(theClass);
		cWriter = new CPrettyPrinter(new PrintWriter(System.out));
		metaWriter = new CPrettyPrinter(new PrintWriter(System.out));
	}
	
	public TACCVisitor(TACClass theClass, File shadowFile) throws ShadowException {
		super(theClass);
		try {
			cFileName = shadowFile.getAbsolutePath().replace(".shadow", ".c");
			metaFileName = shadowFile.getAbsolutePath().replace(".shadow", ".meta");
			
			File cFile = new File(cFileName);
			File metaFile = new File(metaFileName);
			
			cFile.delete();	// always delete the c file
	
			// make sure the meta file exits
//			if(!metaFile.exists())
//				throw new ShadowException("Meta file does not exist!");

			// create the cWriter always with a new file
			cWriter = new CPrettyPrinter(new PrintWriter(new FileOutputStream(cFile, false)));
			
			// open the meta file appending data always
			metaWriter = new CPrettyPrinter(new PrintWriter(new FileWriter(metaFile, true)));
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			throw new ShadowException(e.getLocalizedMessage());
		} catch (IOException e) {
			e.printStackTrace();
			throw new ShadowException(e.getLocalizedMessage());
		}
	}
	

	@Override
	public void startFile() {
		// write out the stuff for the C file
		cWriter.print("/* AUTO-GENERATED FILE, DO NOT EDIT! */");
		cWriter.print("#include <stdio.h>");
		cWriter.print("#include \"" + metaFileName + "\"");	// include the header
		cWriter.print("");
		
		String metaShortName = metaFileName == null ? "" : metaFileName.substring(metaFileName.lastIndexOf(File.separatorChar)+1, metaFileName.length());
		metaShortName = metaShortName.replace('.', '_');
		
		// write out the stuff for the meta file
		metaWriter.print("/* AUTO-GENERATED FILE, DO NOT EDIT! */");
		metaWriter.print("#ifndef " + metaShortName.toUpperCase());
		metaWriter.print("#define " + metaShortName.toUpperCase());
		metaWriter.print("");
	}

	@Override
	public void endFile() {
		metaWriter.print("#endif");
	}

	@Override
	public void startFields() {
		metaWriter.print("struct " + this.getTheClass().getName() + " {");
		metaWriter.indent();
		
		// we need to print function pointers for all of the methods
		List<TACMethod> methods = this.getTheClass().getMethods();
		
		for(TACMethod method:methods) {
			if(method.getName().startsWith("__init"))
				continue;
			StringBuffer sb = new StringBuffer();
			List<Type> retTypes = method.getReturnTypes();
			List<ModifiedType> paramTypes = method.getParamTypes();
			
			// loop through the ret types
			
			if(retTypes.size() != 0)
				sb.append(type2type(retTypes.get(0).getTypeName()));
			else
				sb.append("void");
			
			sb.append(" ");
			sb.append("(*");
			sb.append(method.getName());
			sb.append(")(");

			for(ModifiedType param:paramTypes) {
				sb.append(type2type(param.getType().getTypeName()));
				sb.append(", ");
			}
			
			if(paramTypes.size() == 0) {
				sb.append("void  ");
			}
			
			sb.setCharAt(sb.length()-2, ')');
			sb.setCharAt(sb.length()-1, ';');
			
			metaWriter.print(sb.toString());
		}
		
		metaWriter.print("");
		
		// add in a var to keep track of the reference counts to this object
		metaWriter.print("unsigned int __ref_count");
		metaWriter.print("");
		
		curWriter = metaWriter;
	}

	@Override
	public void endFields() {
		metaWriter.outdent();
		metaWriter.print("};");
		metaWriter.print("");
		curWriter = cWriter;
	}

	@Override
	public void startMethod(TACMethod method) {
		StringBuffer sb = new StringBuffer();
		
		int modifiers = method.getSignature().getASTNode().getModifiers();
		
		// right now we punt on returning more than one thing
		if(method.getReturnTypes().size() == 0) {
			sb.append("void");
		} else {
			sb.append(type2type(method.getReturnTypes().get(0).getTypeName()));
		}
		
		sb.append(" ");
		sb.append(method.getName());
		sb.append("(");
		
		List<String> paramNames = method.getParamNames();
		List<ModifiedType> paramTypes = method.getParamTypes();
		String className = this.getTheClass().getName();

		// first param is always a reference to the class, unless it's static
		if(!ModifierSet.isStatic(modifiers))
			sb.append("struct " + className + "* this, ");

		for(int i=0; i < paramNames.size(); ++i) {
			sb.append(type2type(paramTypes.get(i).getType().getTypeName()));
			sb.append(" ");
			sb.append(paramNames.get(i));
			sb.append(", ");
		}
		
		sb.setCharAt(sb.length()-2, ')');
		
		// methods that are NOT static should be scoped to ONLY this file
		if(!ModifierSet.isStatic(modifiers))
			cWriter.print("static ");
		
		// print to the C file
		cWriter.print(sb.toString() + '{');
		cWriter.indent();
		
		// print to the meta file
		sb.setCharAt(sb.length()-1, ';');
		metaWriter.print(sb.toString());
	}

	@Override
	public void endMethod(TACMethod method) {
		cWriter.outdent();
		cWriter.print("}");
		cWriter.print("");
		
		metaWriter.print("");
	}
	
	public void visit(TACNode node) {
		cWriter.print(node.toString(), node);
	}
	
	/**
	 * Converts a Shadow type to a C type.
	 * @param shadowType
	 * @return
	 */
	private String type2type(String shadowType) {
		String ret = shadowType.replace("[]", "*");
		
		ret = ret.replace("boolean", "int");
		ret = ret.replace("String", "char");

		return ret;
	}
	
	/**
	 * Converts Shadow literals to C literals.
	 * @param shadowLiteral
	 * @return
	 */
	private String lit2lit(String shadowLiteral) {
		if(shadowLiteral.equals("true"))
			return "1";
		else if(shadowLiteral.equals("false"))
			return "0";
		else
			return shadowLiteral;
	}
	
	public void visit(TACAllocation node) {
		TACVariable var = node.getVariable();
		StringBuilder sb = new StringBuilder();
		
		sb.append(type2type(var.getType().toString()));
		sb.append(" ");
		sb.append(var.getSymbol());
		sb.append(";");
		
		// print to the current writer as these can show up anywhere
		curWriter.print(sb.toString(), node);
	}
	
	public void visit(TACAssign node) {
		StringBuilder sb = new StringBuilder();
		
		if(node.getLHS().isField())
			sb.append("this->");
		sb.append(node.getLHS().getSymbol());
		sb.append(" = ");
		sb.append(lit2lit(node.getRHS().getSymbol()));
		sb.append(";");
		
		cWriter.print(sb.toString(), node);
	}
	
	public void visit(TACBinaryOperation node) {
		StringBuilder sb = new StringBuilder();
		
		if(node.getLHS().isField())
			sb.append("this->");
		sb.append(node.getLHS().getSymbol());
		sb.append(" = ");
		sb.append(node.getRHS().getSymbol());
		
		switch(node.getOperation()) {
		case ADDITION: sb.append(" + "); break;
		case AND: sb.append(" & "); break;
		case DIVISION: sb.append(" / "); break;
		case LROTATE: sb.append(" SOME MACRO "); break;
		case LSHIFT: sb.append(" << "); break;
		case MOD: sb.append(" % "); break;
		case MULTIPLICATION: sb.append(" * "); break;
		case OR: sb.append(" | "); break;
		case RROTATE: sb.append(" SOME MACRO "); break;
		case RSHIFT: sb.append(">>"); break;
		case SUBTRACTION: sb.append(" - "); break;
		case XOR: sb.append("^"); break;
		}
		
		sb.append(node.getOperand2().getSymbol());
		sb.append(";");
		
		cWriter.print(sb.toString(), node);
	}
	
	public void visit(TACBranch node) {
		StringBuilder sb = new StringBuilder("if ( ");
		
		if(node.getLHS().isField())
			sb.append("this->");
		sb.append(lit2lit(node.getLHS().getSymbol()));
		
		switch(node.getComparision()) {
		case EQUAL: sb.append(" == "); break;
		case GREATER: sb.append(" > "); break;
		case GREATER_EQUAL: sb.append(" >= "); break;
		case IS: sb.append(" ???? "); break;
		case LESS: sb.append(" < "); break;
		case LESS_EQUAL: sb.append(" <= "); break;
		case NOT_EQUAL: sb.append(" != "); break;
		}
		
		if(node.getRHS().isField())
			sb.append("this->");
		sb.append(lit2lit(node.getRHS().getSymbol()));
		sb.append(" ) { ");
		
		cWriter.print("");
		cWriter.print(sb.toString(), node);
		cWriter.outdent();
	}
	
	public void visitElse() {
		cWriter.print("");
		cWriter.print("else {");
		cWriter.outdent();
	}
	
	public void visit(TACLoop node) {
		// TODO: Implement
	}
	
	public void visit(TACJoin node) {
	}
	
	public void visitJoin(TACJoin node) {
		cWriter.outdent();
		cWriter.print("} ", node);
	}
	
	public void visit(TACNoOp node) {
	}

	public void visit(TACUnaryOperation node) {
		StringBuilder sb = new StringBuilder();
		
		if(node.getLHS().isField())
			sb.append("this->");
		sb.append(node.getLHS());
		
		sb.append(" = ");
		
		sb.append(node.getOperation());
		
		if(node.getRHS().isField())
			sb.append("this->");
		sb.append(node.getRHS());
		
		sb.append(";");
		
		cWriter.print(sb.toString(), node);
	}

	public void visit(TACMethodCall node) {
		StringBuilder sb = new StringBuilder();
		
		//
		// TODO: Remove this hack!
		//
		if(node.getMethodName().equals("printString")) {
			sb.append("printf(\"%s\", ");
		} else {
			sb.append(node.getMethodName());
			sb.append("(");
		}
		
		for(TACVariable param:node.getParameters()) {

			if(param.isField())
				sb.append("this->");
			sb.append(param.getSymbol());
			sb.append(", ");
		}
		
		if(node.getParamCount() != 0) {
			sb.setCharAt(sb.length()-2, ')');
			sb.setCharAt(sb.length()-1, ';');
		}
		
		cWriter.print(sb.toString(), node);
	}
	
	public void visit(TACReturn node) {
		StringBuffer sb = new StringBuffer();
		
		if(node.getReturns().get(0).isField())
			sb.append("this->");
		sb.append("return " + node.getReturns().get(0).getSymbol());
		
		cWriter.print(sb.toString(), node);
	}
}