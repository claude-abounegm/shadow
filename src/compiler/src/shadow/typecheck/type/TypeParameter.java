package shadow.typecheck.type;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


public class TypeParameter extends ClassInterfaceBaseType
{
	private Set<ClassInterfaceBaseType> bounds = new HashSet<ClassInterfaceBaseType>();

	public TypeParameter(String typeName)
	{
		super(typeName, new Modifiers(), null);
		bounds.add(Type.OBJECT);
	}
	
	public void addBound(ClassInterfaceBaseType type) {
		bounds.add(type);
	}
	
	public Set<ClassInterfaceBaseType> getBounds()
	{
		return bounds;
	}

	public boolean canAccept(ModifiedType modifiedType) {
		Type type = modifiedType.getType();
		for( Type bound : bounds )
			if( !type.isSubtype(bound) )
				return false;		
		
		return true;
	}
	
	public boolean canTakeSubstitution(Type type)
	{
		if( type instanceof TypeParameter )
		{
			TypeParameter typeParameter = (TypeParameter) type;
			
			for( Type otherBound : typeParameter.bounds )
			{
				boolean found = false;
				for( Type bound : bounds )
				{
					if( bound.isSubtype(otherBound) )
					{
						found = true;
						break;
					}
				}
				
				if( !found )
					return false;
			}
			
			return true;			
		}
		else
		{
			for( Type bound : bounds )
				if( bound.isSubtype(type) )
					return true;
			
			return false;
		}
	}
	
	public boolean isSubtype(Type type)
	{		
		if( equals(type) || type == Type.OBJECT )
			return true;
		
		for( Type bound : bounds )
			if( bound.isSubtype(type) )
				return true;
		
		return false;
	}
	
	public ClassInterfaceBaseType replace(SequenceType values, SequenceType replacements )
	{
		for( int i = 0; i < values.size(); i++ )
		{
			if( values.get(i).getType().getTypeName().equals(getTypeName()))
				return (ClassInterfaceBaseType) replacements.get(i).getType();
		}
		
		return this;
	}
	
	public String toString() {
		StringBuilder builder = new StringBuilder(getTypeName());
		boolean first = true;
		
		if( bounds.size() > 1 ) //always contains Object
			builder.append(" is ");
		
		for(Type bound : bounds )
		{			
			if( !first )
				builder.append(" and ");
			
			if( bound != Type.OBJECT )
			{
				builder.append(bound.toString());				
				first = false;
			}
		}
		
		return builder.toString();
	}
	
	public List<MethodSignature> getMethods(String methodName)
	{
		Set<MethodSignature> signatures = new HashSet<MethodSignature>();
		for(ClassInterfaceBaseType bound : bounds )					
			signatures.addAll(bound.getMethods(methodName));
		
		return new ArrayList<MethodSignature>(signatures);
	}
	
}