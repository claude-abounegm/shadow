package shadow;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.JarURLConnection;
import java.net.URISyntaxException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.Unmarshaller;

import org.apache.logging.log4j.Logger;

import shadow.jaxb.Shadow;

/** 
 * Represents the current compiler settings/configuration. This is a globally
 * accessible singleton.
 */
public class Configuration {
	
	public static final String DEFAULT_CONFIG_NAME = "shadow.xml";
	
	private static Configuration globalConfig;
	
	private static final Logger logger = Loggers.SHADOW;
	
	private Path configFile;
	
	// Configuration fields
	private int arch;
	private String os;
	private String target;
	private Path systemPath;
	private String llc;
	private String llvmLink;
	private String opt;
	private List<Path> importPaths;
	private List<String> linkCommand;
	
	/** 
	 * Builds the Configuration if necessary. Must be run at least once before
	 * getConfiguration() is called.
	 */
	public static Configuration buildConfiguration(String mainFilePath, String configFilePath, boolean forceRebuild) throws ConfigurationException, IOException {
		
		if( globalConfig == null || forceRebuild )
			globalConfig = new Configuration(mainFilePath, configFilePath);
		
		return globalConfig;
	}
	
	/** Retrieves the global compiler Configuration */
	public static Configuration getConfiguration() throws ConfigurationException {
		
		if( globalConfig == null )
			throw new ConfigurationException("Configuration data must be built before being accessed.");
		
		return globalConfig;
	}
	
	/** Hidden constructor for instantiating the Configuration */
	private Configuration(String mainFilePath, String configFilePath) throws ConfigurationException, IOException {
		
		// Attempt to locate hierarchy of config files
		configFile = locateConfig(mainFilePath, configFilePath);
		
		
		// If a config file was located, parse it
		if( configFile != null ) 
			parse(configFile);
		
		inferSettings(); // Auto-fill any empty fields
	}

	/**
	 * Attempts to find a specified (or unspecified) config file. There are
	 * three places to look for a config file. In priority order:
	 * 
	 * 1. If the file specified on the command line
	 * 		-As is, if absolute
	 * 		-Relative to the source directory
	 * 		-Relative to the working directory, with a warning
	 * 		-Relative to the running directory, with a warning
	 * 		-Exception if not found
	 * 2. A file in the source directory with the default name
	 * 3. A file in the running directory with the default name
	 * 4. A file in the working directory with the default name
	 */
	private Path locateConfig(String mainFilePath, String configFilePath) throws FileNotFoundException, ConfigurationException {
		
		// Get the various search directories
		Path sourceDir = mainFilePath == null ? null : Paths.get(mainFilePath).toAbsolutePath().getParent().toAbsolutePath();
		Path workingDir = Paths.get("").toAbsolutePath();
		Path runningDir = getRunningDirectory().toAbsolutePath();
		
		Path defaultFile = Paths.get(DEFAULT_CONFIG_NAME);

		// 1: Config file specified on the command line
		
		if( configFilePath != null ) {
			
			Path configFile = Paths.get(configFilePath);
			
			// If absolute, no need to resolve
			if( configFile.isAbsolute() ) {
				if( !Files.exists(configFile) )
					throw new FileNotFoundException("Configuration file "
							+ configFile.toAbsolutePath() + " does not exist");
				
				return configFile;
			}
			// If not, first look in the source directory
			else if( sourceDir != null && Files.exists(sourceDir.resolve(configFile)) ) {
				return sourceDir.resolve(configFile);
			}
			// Look in the working directory
			else if( Files.exists(workingDir.resolve(configFile)) ) {
				logger.warn("WARNING: Falling back on the working directory " + workingDir
						+ " in order to find the config file " + configFile
						+ ". This should usually only be expected during testing");
				return workingDir.resolve(configFile);
			}
			// Look in the running directory of the program
			else if( Files.exists(runningDir.resolve(configFile)) ) {
				logger.warn("WARNING: Falling back on the running directory " + runningDir
						+ " in order to find the config file " + configFile
						+ ". This should usually only be expected during testing");
				return runningDir.resolve(configFile);
			}
			else {
				throw new FileNotFoundException("Configuration file "
						+ configFile + " does not exist");
			}
		}
		/// 2: Default config file, local to the main source file
		else if( sourceDir != null && Files.exists(sourceDir.resolve(defaultFile)) ) {
				return sourceDir.resolve(defaultFile);
		}
		/// 3: Default config file, local to the running directory
		else if( Files.exists(runningDir.resolve(defaultFile)) ) {
			return runningDir.resolve(defaultFile);
		}
		/// 4: Default config file, local to the working directory
		else if( Files.exists(workingDir.resolve(defaultFile)) ) {
			return workingDir.resolve(defaultFile);
		}
		else {
			return null;
		}
	}
	
	/** Auto-detects values for unfilled fields */
	private void inferSettings() throws ConfigurationException, IOException {
		
		// TODO: Consider moving default value code into the individual getter
		// methods
		
		if( arch == 0 ) {
			if( System.getProperty("os.arch").contains("64") )
				arch = 64;
			else
				arch = 32;
		}
		
		if( os == null ) {
			String osName = System.getProperty("os.name").toLowerCase();
			
			if( osName.contains("windows") )
				os = "Windows";
			else if( osName.contains("mac"))
				os = "Mac";
			else if( osName.contains("linux") )     
				os = "Linux";
			else {
				logger.info("Unrecognized operating system \"" + System.getProperty("os.name")
							+ "\" detected, defaulting to Linux.ll");
				os = "Linux";
			}
		}
		
		// Make sure that llc is specified early, since it's used to get the default target
		if( llc == null )
			llc = "llc";
		
		if( opt == null )
			opt = "opt";
		
		if( llvmLink == null )
			llvmLink = "llvm-link";
		
		if( target == null )
			target = getDefaultTarget();
		
		if( linkCommand == null ) {		
			linkCommand = new ArrayList<String>();
			
			if( getOs().equals("Mac")) {
				linkCommand.add("clang");				
				linkCommand.add("-x");
				linkCommand.add("assembler");
				linkCommand.add("-");
				linkCommand.add("-lm");
				linkCommand.add("-lSystem");
			}			
			else {
				linkCommand.add("g++");
				linkCommand.add("-x");
				linkCommand.add("assembler");
				linkCommand.add("-");
				
				if( getOs().equals("Linux") ) {
					linkCommand.add("-lm");
					linkCommand.add("-lrt");
					linkCommand.add("-pthread");
				} /*else {
					// we need this for MinGW pthreads
					linkCommand.add("-static");
				}*/
			}
		}

		if( systemPath == null )
			systemPath = getRunningDirectory();
		
		if( importPaths == null)
			importPaths = new ArrayList<Path>();
		
		// The import paths list must contain an "empty" path that can later be
		// resolved against source files
		importPaths.add(Paths.get("." + File.separator));
	}
	
	/** Parses a config file and fills the corresponding fields */
	private void parse(Path configFile) {
		
		try {
			JAXBContext jaxbContext = JAXBContext.newInstance(Shadow.class);
	 
			Unmarshaller jaxbUnmarshaller = jaxbContext.createUnmarshaller();
			Shadow configuration = (Shadow) jaxbUnmarshaller.unmarshal(configFile.toFile());
			
			Integer arch = configuration.getArch();
			if( arch != null )
				this.arch = arch;
			
			addImports(configuration.getImport());
			
			String linkCommand = configuration.getLink(); 
			if( linkCommand != null )
				setLinkCommand(linkCommand);
			
			os = configuration.getOs();			
			target = configuration.getTarget();
			llc = configuration.getLlc();
			opt = configuration.getOpt();
			llvmLink = configuration.getLlvmLink();
			
			String systemPath = configuration.getSystem();
			if( systemPath != null )
				setSystemImport(systemPath);
		} 
		catch(Exception e) {
			System.err.println("ERROR PARSING CONFIGURATION FILE: " + configFile.toAbsolutePath());
			e.printStackTrace();
		}
	}
	
	public void setArch(int arch) {		
		if(this.arch == 0)
			this.arch = arch;
	}
	
	public int getArch() {		
		return arch;
	}
	
	public void setOs(String os) {		
		if(this.os == null)
			this.os = os;
	}

	public String getOs() {		
		return os;
	}

	public void addImports(List<String> paths) {
		for( String path : paths )
			addImport(path);
	}
	
	public void addImport(String importPath) {		
		if ( importPaths == null )
			importPaths = new ArrayList<Path>();
		
		Path newImportPath = Paths.get(importPath);
		newImportPath = configFile.getParent().resolve(newImportPath);
		
		importPaths.add(newImportPath);
	}

	public List<Path> getImports() {		
		return importPaths;
	}

	public void setSystemImport(String systemImportPath) {		
		if(systemPath == null) {
			systemPath = Paths.get(systemImportPath);
			systemPath = configFile.getParent().resolve(systemPath);
		}
	}
	
	public Path getSystemImport() {		
		return systemPath;
	}
	
	public void setLinkCommand(String linkCommand) {		
		if( this.linkCommand == null ) {			
			this.linkCommand = new ArrayList<String>();
			this.linkCommand.addAll(Arrays.asList(linkCommand.split("\\s+")));
		}
	}
	
	public List<String> getLinkCommand(Job currentJob) {		
		// Merge the output commands with the linker commands
		linkCommand.addAll(currentJob.getOutputCommand());
		return linkCommand;
	}
	
	public void setTarget(String target) {		
		if( this.target == null )
			this.target = target;
	}
	
	public String getTarget() {		
		return target;
	}
	
	/** Gets the directory within which the compiler is currently running */
	public static Path getRunningDirectory() throws ConfigurationException {		
		try {
			URL path = Main.class.getProtectionDomain().getCodeSource().getLocation();
			
			// This is used to remove the "jar:" from the path when called through reflection. 
			if(path.toString().startsWith("jar:file")) {
				path = ((JarURLConnection) path.openConnection()).getJarFileURL();
				return Paths.get(path.getPath()).getParent().toAbsolutePath();
			}
			
			return Paths.get(path.toURI()).getParent().toAbsolutePath();
		}
		catch( SecurityException e ) {
			throw new ConfigurationException("Insufficient permissions to access the running directory");
		}
		catch (IOException e) {
			throw new ConfigurationException(e.toString());
		} catch (URISyntaxException e) {
			throw new ConfigurationException(e.toString());
		}
	}
	
	public String getOpt() {
		return opt;
	}
	
	public String getLlc() {
		return llc;
	}
	
	public String getLlvmLink() {
		return llvmLink;
	}
	
	/** Returns the target platform to be used by the LLVM compiler */
	public String getDefaultTarget() throws ConfigurationException {
		// Some reference available here:
		// http://llvm.org/docs/doxygen/html/Triple_8h_source.html
		
		// Calling 'llc -version' for current target information
		// Note: Most of the LLVM tools also have this option
		try {
			Process process = new ProcessBuilder(getLlc(), "-version").redirectErrorStream(true).start();
			BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
	
			String versionOutput = "";
			String line = null;
			while( (line = reader.readLine()) != null )
			   versionOutput += line + System.lineSeparator();			
			
			// Create the regular expression required to find the target "triple"
			Pattern pattern = Pattern.compile("(Default target:\\s)([\\w\\-]+)");
			Matcher matcher = pattern.matcher(versionOutput);
			
			if( matcher.find() )
				return matcher.group(2);
			else
				throw new ConfigurationException(
						"Unable to find target in 'llc -version' output:" + System.lineSeparator() 
						+ versionOutput);
		}
		catch(IOException e) {
			throw new ConfigurationException("LLVM installation not found!"); 
		}
	}
	
	public static String getLLVMVersion() {
		try {
			Process process = new ProcessBuilder(getConfiguration().getLlc(), "-version").redirectErrorStream(true).start();
			BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
	
			String versionOutput = "";
			String line = null;
			while( (line = reader.readLine()) != null )
			   versionOutput += line + System.lineSeparator();			
			
			// Create the regular expression required to find the version
			Pattern pattern = Pattern.compile("(LLVM version\\s)(\\d+(\\.\\d+)*)");
			Matcher matcher = pattern.matcher(versionOutput);
			
			if( matcher.find() )
				return matcher.group(2);
		}
		catch(IOException e) {			 
		}
		catch (ConfigurationException e) {		
		}
		
		return "";
	}
	
	public static String getLLVMInformation() {
		// Calling 'llc -version' for LLVM information
		// Note: Most of the LLVM tools also have this option
		try {		
			Process process = new ProcessBuilder(getConfiguration().getLlc(), "-version").redirectErrorStream(true).start();
			BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
	
			String information = "";
			String line = null;
			while( (line = reader.readLine()) != null && !line.isEmpty() )
			   information += line + System.lineSeparator();
			
			return information;
		}
		catch(IOException | ConfigurationException e) {
			return "LLVM installation not found!"; 
		}
	}
}
 
