package shadow.tac.nodes;

import shadow.parser.ShadowException;
import shadow.tac.TACVisitor;
import shadow.typecheck.type.Type;

public class TACLandingpad extends TACOperand
{
	private TACBlock block;

	public TACLandingpad(TACNode node, TACBlock blockRef)
	{
		super(node);
		block = blockRef;
	}

	public TACBlock getBlock()
	{
		return block;
	}

	@Override
	public Type getType()
	{
		throw new UnsupportedOperationException();
	}

	@Override
	public int getNumOperands()
	{
		return 1;
	}
	@Override
	public TACOperand getOperand(int num)
	{
		if (num == 0)
			return getBlock();
		throw new IndexOutOfBoundsException();
	}

	@Override
	public void accept(TACVisitor visitor) throws ShadowException
	{
		visitor.visit(this);
	}
}