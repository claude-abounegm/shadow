/* Generated By:JJTree: Do not edit this line. ASTSequenceVariable.java Version 4.3 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=true,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
package shadow.parser.javacc;

public
@SuppressWarnings("all")
class ASTSequenceVariable extends SimpleNode {
  public ASTSequenceVariable(int id) {
    super(id);
  }

  public ASTSequenceVariable(ShadowParser p, int id) {
    super(p, id);
  }

  /** Accept the visitor. **/
  public Object jjtAccept(ShadowParserVisitor visitor, Boolean data) throws ShadowException {
    return visitor.visit(this, data);
  }
}
/* JavaCC - OriginalChecksum=51b1176ea1202be494ffa35715596516 (do not edit this line) */
