/* Generated By:JJTree: Do not edit this line. ASTInlineMethodDeclaration.java Version 4.3 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=true,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
package shadow.parser.javacc;

public
@SuppressWarnings("all")
class ASTInlineMethodDeclaration extends SignatureNode {
  public ASTInlineMethodDeclaration(int id) {
    super(id);
  }

  public ASTInlineMethodDeclaration(ShadowParser p, int id) {
    super(p, id);
  }

  /** Accept the visitor. **/
  public Object jjtAccept(ShadowParserVisitor visitor, Boolean data) throws ShadowException {
    return visitor.visit(this, data);
  }
}
/* JavaCC - OriginalChecksum=53245b51e686e21038e35353d8befed2 (do not edit this line) */
