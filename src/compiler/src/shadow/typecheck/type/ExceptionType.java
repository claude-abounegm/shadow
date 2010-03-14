package shadow.typecheck.type;

import shadow.typecheck.type.Type.Kind;


public class ExceptionType extends ClassType
{
	public ExceptionType(String typeName, int modifiers, Type outer ) {
		this( typeName, modifiers, outer, Type.EXCEPTION );
	}
	
	public ExceptionType(String typeName, int modifiers, Type outer, ClassType extendType ) {
		super( typeName, modifiers, outer, Kind.EXCEPTION );
		setExtendType( extendType );
	}
}