/* Generated By:JJTree: Do not edit this line. ASTUnqualifiedName.java Version 4.3 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=true,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
package shadow.parser.javacc;

public
@SuppressWarnings("all")
class ASTUnqualifiedName extends SimpleNode {
  public ASTUnqualifiedName(int id) {
    super(id);
  }

  public ASTUnqualifiedName(ShadowParser p, int id) {
    super(p, id);
  }


  /** Accept the visitor. **/
  public Object jjtAccept(ShadowParserVisitor visitor, Boolean data) throws ShadowException {
    return visitor.visit(this, data);
  }
}
/* JavaCC - OriginalChecksum=be4c4fa8cae9383fc1754110ba5806f4 (do not edit this line) */
