/* Generated By:JJTree: Do not edit this line. ASTResultTypes.java Version 4.3 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=true,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
package shadow.parser.javacc;

import java.util.ArrayList;
import java.util.List;

import shadow.typecheck.type.ModifiedType;
import shadow.typecheck.type.Type;

public
@SuppressWarnings("all")
class ASTResultTypes extends SequenceNode {
	 
	
  public ASTResultTypes(int id) {
    super(id);
  }

  public ASTResultTypes(ShadowParser p, int id) {
    super(p, id);
  }


  /** Accept the visitor. **/
  public Object jjtAccept(ShadowParserVisitor visitor, Boolean secondVisit) throws ShadowException {
    return visitor.visit(this, secondVisit);
  }
}
/* JavaCC - OriginalChecksum=2956568701fbd1dafda51be3ddda94f9 (do not edit this line) */
