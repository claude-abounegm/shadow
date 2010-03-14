package shadow.TAC.test;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

import shadow.TAC.TACBuilder;
import shadow.parser.javacc.ParseException;
import shadow.parser.javacc.ShadowException;
import shadow.parser.javacc.ShadowParser;
import shadow.parser.javacc.SimpleNode;
import shadow.test.BaseTest;
import shadow.typecheck.TypeChecker;
import shadow.typecheck.test.TypeCheckerTest;

public class TACTest extends BaseTest {
	private boolean dump;
	private boolean debug;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException, ShadowException {
		TACTest tact = new TACTest(true, true);
		
		// no args, we test everything
		if(args.length == 0)
			tact.testAll();
		else {
			for(String arg:args) {
				tact.testAll(new File(arg));
			}
		}	
	}
	
	public TACTest(boolean dump, boolean debug) {
		super("./src/shadow/typecheck/test");	// change this maybe?
		this.dump = dump;
		this.debug = debug;
	}
	
	protected void runTest(File sourceFile) throws ShadowException {
	    try {
	    	System.out.println("CHECKING: " + sourceFile.getPath());
	        FileInputStream fis = new FileInputStream(sourceFile);        
	        ShadowParser parser = new ShadowParser(fis);
	        TypeChecker tc = new TypeChecker(false);
	        TACBuilder tacBuilder = new TACBuilder();
	        SimpleNode node = parser.CompilationUnit();
	        
	        if(dump)
	        	node.dump("");
	        
	        long startTime = System.currentTimeMillis();

	        // type check the tree
	        boolean result = tc.typeCheck(node);
	        
	        if(!result) {
	        	System.out.println(sourceFile.getPath() + "FAILED TO TYPE CHECK");
	        	throw new ShadowException("");
	        }
	        
	        tacBuilder.build(node);

	        long stopTime = System.currentTimeMillis();
	        long runTime = stopTime - startTime;

	    } catch (ParseException e) {
	        System.out.println("BAD PARSE");
	        System.out.println(e.getMessage());
	        throw new ShadowException(e.getMessage());
	    } catch (ShadowException se) {
	    	System.out.println("BAD TYPE CHECK");
	    	System.out.println(se.getMessage());
	        throw se;
	    } catch (Error e) {
	        System.out.println("Ooops");
	        System.out.println(e.getMessage());
	        e.printStackTrace(System.out);
	        throw new ShadowException(e.getMessage());
	    } catch (FileNotFoundException e) {
	        System.out.println(e.getMessage());
	        throw new ShadowException(e.getMessage());
	    }       
	}
}