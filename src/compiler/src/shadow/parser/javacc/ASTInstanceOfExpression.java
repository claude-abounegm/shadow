/* Generated By:JJTree: Do not edit this line. ASTInstanceOfExpression.java Version 4.3 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=true,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
package shadow.parser.javacc;

public
@SuppressWarnings("all")
class ASTInstanceOfExpression extends SimpleNode {
  public ASTInstanceOfExpression(int id) {
    super(id);
  }

  public ASTInstanceOfExpression(ShadowParser p, int id) {
    super(p, id);
  }


  /** Accept the visitor. **/
  public Object jjtAccept(ShadowParserVisitor visitor, Object data) {
    return visitor.visit(this, data);
  }
}
/* JavaCC - OriginalChecksum=af3008ea247b8ad4649d679646777bd9 (do not edit this line) */