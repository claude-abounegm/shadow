package shadow.typecheck.type;

public interface ModifiedType
{
	public Type getType();
	public int getModifiers();
	//public ModifiedType replace(SequenceType values, SequenceType replacements );
}
