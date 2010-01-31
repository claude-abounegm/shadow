package shadow.typecheck.type;

import java.util.ArrayList;

public class InterfaceType extends ClassInterfaceBaseType {
	protected ArrayList<ClassType> extendType;

	public InterfaceType(String typeName) {
		super(typeName);
	}

	public InterfaceType(String typeName, int modifiers) {
		super(typeName, modifiers);
	}

	public InterfaceType(String typeName, int modifiers, Type enclosing) {
		super(typeName, modifiers, enclosing);
	}

	public InterfaceType(String typeName, int modifiers, Type enclosing, Type parent) {
		super(typeName, modifiers, enclosing, parent);
	}

}