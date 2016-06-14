package shadow.tac;

import shadow.parser.javacc.ShadowException;
import shadow.tac.nodes.TACBinary;
import shadow.tac.nodes.TACBranch;
import shadow.tac.nodes.TACCall;
import shadow.tac.nodes.TACCast;
import shadow.tac.nodes.TACCatch;
import shadow.tac.nodes.TACClass;
import shadow.tac.nodes.TACClass.TACClassData;
import shadow.tac.nodes.TACClass.TACMethodTable;
import shadow.tac.nodes.TACCopyMemory;
import shadow.tac.nodes.TACGlobal;
import shadow.tac.nodes.TACLabelRef.TACLabel;
import shadow.tac.nodes.TACLandingpad;
import shadow.tac.nodes.TACLength;
import shadow.tac.nodes.TACLiteral;
import shadow.tac.nodes.TACLoad;
import shadow.tac.nodes.TACLocalLoad;
import shadow.tac.nodes.TACLocalStore;
import shadow.tac.nodes.TACLongToPointer;
import shadow.tac.nodes.TACMethodRef;
import shadow.tac.nodes.TACNewArray;
import shadow.tac.nodes.TACNewObject;
import shadow.tac.nodes.TACNodeRef;
import shadow.tac.nodes.TACNot;
import shadow.tac.nodes.TACParameter;
import shadow.tac.nodes.TACPhiRef;
import shadow.tac.nodes.TACPhiRef.TACPhi;
import shadow.tac.nodes.TACPhiStore;
import shadow.tac.nodes.TACPointerToLong;
import shadow.tac.nodes.TACResume;
import shadow.tac.nodes.TACReturn;
import shadow.tac.nodes.TACSame;
import shadow.tac.nodes.TACSequence;
import shadow.tac.nodes.TACSequenceElement;
import shadow.tac.nodes.TACStore;
import shadow.tac.nodes.TACThrow;
import shadow.tac.nodes.TACTypeId;
import shadow.tac.nodes.TACUnary;
import shadow.tac.nodes.TACUnwind;

public interface TACVisitor
{	
	public abstract void visit(TACBinary node) throws ShadowException;	
	public abstract void visit(TACBlock node) throws ShadowException;
	public abstract void visit(TACBranch node) throws ShadowException;
	public abstract void visit(TACCall node) throws ShadowException;
	public abstract void visit(TACCast node) throws ShadowException;
	public abstract void visit(TACCatch node) throws ShadowException;
	public abstract void visit(TACClass node) throws ShadowException;
	public abstract void visit(TACClassData node) throws ShadowException;		
	public abstract void visit(TACCopyMemory node) throws ShadowException;
	public abstract void visit(TACLabel node) throws ShadowException;	
	public abstract void visit(TACLandingpad node) throws ShadowException;
	public abstract void visit(TACLength node) throws ShadowException;
	public abstract void visit(TACLiteral node) throws ShadowException;
	public abstract void visit(TACLoad node) throws ShadowException;
	public abstract void visit(TACLocalLoad node) throws ShadowException;
	public abstract void visit(TACLocalStore node) throws ShadowException;
	public abstract void visit(TACLongToPointer node) throws ShadowException;
	public abstract void visit(TACMethodRef node) throws ShadowException;
	public abstract void visit(TACMethodTable tacMethodTable) throws ShadowException;
	public abstract void visit(TACNewArray node) throws ShadowException;
	public abstract void visit(TACNewObject node) throws ShadowException;
	public abstract void visit(TACNodeRef node) throws ShadowException;
	public abstract void visit(TACNot node) throws ShadowException;
	public abstract void visit(TACPhi node) throws ShadowException;
	public abstract void visit(TACPhiStore node) throws ShadowException;
	public abstract void visit(TACPhiRef node) throws ShadowException;
	public abstract void visit(TACPointerToLong node) throws ShadowException;
	public abstract void visit(TACSequenceElement node) throws ShadowException;
	public abstract void visit(TACResume node) throws ShadowException;
	public abstract void visit(TACReturn node) throws ShadowException;
	public abstract void visit(TACSame node) throws ShadowException;
	public abstract void visit(TACSequence node) throws ShadowException;
	public abstract void visit(TACStore node) throws ShadowException;
	public abstract void visit(TACThrow node) throws ShadowException;
	public abstract void visit(TACTypeId node) throws ShadowException;
	public abstract void visit(TACUnary node) throws ShadowException;
	public abstract void visit(TACUnwind node) throws ShadowException;
	public abstract void visit(TACGlobal node) throws ShadowException;
	public abstract void visit(TACParameter node) throws ShadowException;
}
