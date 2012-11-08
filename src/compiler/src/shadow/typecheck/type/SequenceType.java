package shadow.typecheck.type;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

import shadow.parser.javacc.ShadowParser.ModifierSet;
import shadow.parser.javacc.SimpleNode;

public class SequenceType extends Type implements Iterable<ModifiedType>, List<ModifiedType>
{	
	private List<ModifiedType> types; /** List of return types */	

	public SequenceType() {		
		this( new ArrayList<ModifiedType>()  );		
	}

	public SequenceType(List<ModifiedType> modifiedTypes)
	{
		super(null, 0, null);		
		types = modifiedTypes;
	}	
	
	@Override
	public int size()
	{
		return types.size();
	}
	
	@Override
	public boolean isEmpty()
	{
		return types.isEmpty();
	}
	
	public boolean canAccept( List<ModifiedType> inputTypes, List<String> reasons )
	{		
		if( types.size() != inputTypes.size() )
			return false;
		
		for( int i = 0; i < types.size(); i++ )
		{	
			Type inputType = inputTypes.get(i).getType();
			int inputModifiers  = inputTypes.get(i).getModifiers();
			Type type = types.get(i).getType();
			int modifiers = types.get(i).getModifiers();
							
			if( type instanceof TypeParameter  )
			{			
				TypeParameter parameter = (TypeParameter) type;
				if( !parameter.canAccept( inputTypes.get(i)  ) )
				{
					if( reasons != null )
						reasons.add(inputType + " cannot be substituted for " + type);
					return false;
				}
			}
			else if( !inputType.isSubtype(type) )
			{
				if( reasons != null )
					reasons.add(inputType + " is not a subtype of " + type);
				return false;
			}
			
			//if either type is immutable, it will work out no matter what
			//if both are mutable, their modifiers had better both be immutable or both mutable
			if( !ModifierSet.isImmutable(type.getModifiers()) && !ModifierSet.isImmutable(inputType.getModifiers()) &&
				ModifierSet.isImmutable(modifiers) != ModifierSet.isImmutable(inputModifiers) )
			{
				if( reasons != null )
				{				
					String reason = "";
					if( ModifierSet.isImmutable(modifiers) )
						reason += "immutable ";
					reason += type + " is not compatible with ";
					if( ModifierSet.isImmutable(inputModifiers) )
						reason += "immutable ";
					reason += inputType;
					
					reasons.add(reason);
				}
				return false;
				
				
			}
			
			if( !ModifierSet.isNullable(modifiers) && ModifierSet.isNullable(inputModifiers) )
			{
				if( reasons != null )
					reasons.add("non-nullable " + type + " cannot accept nullable " + inputType);
				
				return false;
			}		
			
		}
		
		return true;		
	}
	
	public boolean canAccept( List<ModifiedType> inputTypes )
	{		
		return canAccept( inputTypes, null);		
	}
	
	public boolean canAccept( ModifiedType type )
	{		
		return canAccept(type, null);		
	}
	
	public boolean canAccept( ModifiedType type, List<String> reasons )
	{		
		ArrayList<ModifiedType> list = new ArrayList<ModifiedType>(1);
		list.add(type);
		
		return canAccept(list, reasons);		
	}
	
	

	public String toString() {
		StringBuilder builder = new StringBuilder("(");
		boolean first = true;
		
		for(ModifiedType type: types)
		{			
			if( !first )
				builder.append(", ");
			
			Type p = type.getType();
			
			if( ModifierSet.isFinal(type.getModifiers()))
				builder.append("final ");
			
			if( ModifierSet.isNullable(type.getModifiers()))
				builder.append("nullable ");
			
			if( ModifierSet.isImmutable(type.getModifiers()))
				builder.append("immutable ");
			

			builder.append(p.toString());
			
			first = false;
		}
		
		builder.append(")");
		
		return builder.toString();
	}
	
	public boolean isAssignable()
	{
		for( ModifiedType type : this )
			if( ModifierSet.isFinal(type.getModifiers()) )
				return false;	
		
		return true;		
	}

	public boolean equals(Object o)
	{
		if (o == Type.NULL)
			return true;
		if( o != null && o instanceof SequenceType )
			return exactlyMatches((SequenceType)o);
		else
			return false;
	}
	
	@Override
	public SequenceType replace(SequenceType values, SequenceType replacements)
	{		
		SequenceType temp = new SequenceType();
		
		for( int i = 0; i < types.size(); i++ )
		{
			ModifiedType type = types.get(i);
			SimpleModifiedType dummy = new SimpleModifiedType( type.getType().replace( values, replacements), type.getModifiers() );
			temp.add( dummy );
		}
		
		return temp;
	}
		
	public boolean matches(List<ModifiedType> inputTypes)
	{
		if( types.size() != inputTypes.size() )
			return false;
		
	
		for( int i = 0; i < types.size(); i++ )		
			if( !inputTypes.get(i).getType().equals(getType(i)) )
				return false;
		
		return true;		
	}
	
	
	public boolean exactlyMatches(List<ModifiedType> inputTypes)
	{
		if( types.size() != inputTypes.size() )
			return false;	
	
		for( int i = 0; i < types.size(); i++ )		
			if( !inputTypes.get(i).getType().equals(getType(i)) || inputTypes.get(i).getModifiers() != get(i).getModifiers() )
				return false;
		
		return true;		
	}
	
	public void setNodeType(SimpleNode node)
	{
		if( types.size() == 1 )
		{
			ModifiedType modifiedType = types.get(0); 
			node.setType(modifiedType.getType());
			if( ModifierSet.isNullable(modifiedType.getModifiers()))
				node.addModifier(ModifierSet.NULLABLE);			
		}
		else
			node.setType(this);
	}

	@Override
	public Iterator<ModifiedType> iterator() {		
		return types.iterator();
	}	

	@Override
	public ModifiedType get(int i) {		
		return types.get(i);
	}
	
	public Type getType(int i) {		
		return types.get(i).getType();
	}
	
	public int getModifiers(int i) {		
		return types.get(i).getModifiers();
	}


	@Override
	public boolean contains(Object o) {
		return types.contains(o);
	}

	@Override
	public Object[] toArray() {		
		return types.toArray();
	}

	@Override
	public <T> T[] toArray(T[] a) {
		return types.toArray(a);		
	}

	@Override
	public boolean add(ModifiedType e) {
		return types.add(e);
	}

	@Override
	public boolean remove(Object o) {		
		return types.remove(o);
	}

	@Override
	public boolean containsAll(Collection<?> c) {		
		return types.containsAll(c);
	}

	@Override
	public boolean addAll(Collection<? extends ModifiedType> c) {
		return types.addAll(c);
	}

	@Override
	public boolean addAll(int index, Collection<? extends ModifiedType> c) {
		return types.addAll(index, c);
	}

	@Override
	public boolean removeAll(Collection<?> c) {		
		return types.removeAll(c);
	}

	@Override
	public boolean retainAll(Collection<?> c) {		
		return types.retainAll(c);
	}

	@Override
	public void clear() {
		types.clear();
	}

	@Override
	public ModifiedType set(int index, ModifiedType element) {		
		return types.set(index, element);
	}

	@Override
	public void add(int index, ModifiedType element) {
		types.add(index, element);		
	}

	@Override
	public ModifiedType remove(int index) {		
		return types.remove(index);
	}

	@Override
	public int indexOf(Object o) {
		return types.indexOf(o);
	}

	@Override
	public int lastIndexOf(Object o) {		
		return types.lastIndexOf(o);
	}

	@Override
	public ListIterator<ModifiedType> listIterator() {		
		return types.listIterator();
	}

	@Override
	public ListIterator<ModifiedType> listIterator(int index) {		
		return types.listIterator(index);
	}

	@Override
	public List<ModifiedType> subList(int fromIndex, int toIndex) {		
		return types.subList(fromIndex, toIndex);
	}

	public boolean canSubstitute(List<ModifiedType> inputTypes) {	
		if( types.size() != inputTypes.size() )
			return false;
		
		for( int i = 0; i < types.size(); i++ )
		{
			Type input = inputTypes.get(i).getType();
			Type type = types.get(i).getType();
			
			if( type instanceof TypeParameter )
			{
				TypeParameter parameter = (TypeParameter)type;
				if( !parameter.canTakeSubstitution(input))
					return false;				
			}			
			else if( !input.isSubtype(type) )
				return false;
		}
		
		return true;	
	}
	
	public boolean isSubtype(Type t)
	{
		if( equals(t) )
			return true;		
		
		if ( t instanceof SequenceType )
			return canAccept((SequenceType)t);
		else
			return false;
	}
}
