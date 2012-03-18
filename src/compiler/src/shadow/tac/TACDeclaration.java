package shadow.tac;

import shadow.tac.nodes.TACNode;

public abstract class TACDeclaration
{
	private TACNode entry, exit;
	public TACDeclaration()
	{
		entry = exit = null;
	}
	public TACDeclaration(TACNode singleNode)
	{
		entry = exit = singleNode;
	}
	public TACDeclaration(TACDeclaration body)
	{
		entry = body.entry;
		exit = body.exit;
	}
	public TACDeclaration(TACNode entryNode, TACNode exitNode)
	{
		entry = entryNode;
		exit = exitNode;
	}

	public TACNode getEntryNode()
	{
		return entry;
	}
	public TACNode getExitNode()
	{
		return exit;
	}
	public TACNode getNode()
	{
		return exit;
	}

	public void append(TACNode node)
	{
		if (exit == null)
			entry = exit = node;
		else
		{
			exit.append(node);
			exit = node;
		}
	}
	public void append(TACDeclaration node)
	{
		if (exit == null)
		{
			entry = node.getEntryNode();
			exit = node.getExitNode();
		}
		else
		{
			exit.append(node.getEntryNode());
			exit = node.getExitNode();
		}
	}
	
	public boolean isEmpty()
	{
		return entry == null && exit == null;
	}
	
	@Override
	public String toString()
	{
		return getNode().toString();
	}
}