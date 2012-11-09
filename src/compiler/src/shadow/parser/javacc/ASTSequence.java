/* Generated By:JJTree: Do not edit this line. ASTSequence.java Version 4.3 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=true,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
package shadow.parser.javacc;


public
class ASTSequence extends SimpleNode {
  public ASTSequence(int id) {
    super(id);
  }

  public ASTSequence(ShadowParser p, int id) {
    super(p, id);
  }
  
  public boolean isAssignable()
  {
	  for( int i = 0; i < jjtGetNumChildren(); i++ )
		  if( !jjtGetChild(i).getModifiers().isAssignable() )
				  return false;
		  
		  
	  return true;
  }


  /** Accept the visitor. **/
  public Object jjtAccept(ShadowParserVisitor visitor, Boolean data) throws ShadowException {
    return visitor.visit(this, data);
  }
}
/* JavaCC - OriginalChecksum=414961a60ac37535dd79699b1fc4ebd7 (do not edit this line) */
