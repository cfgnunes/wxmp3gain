#!/bin/bash
# ======================================================================
# Setup
# ======================================================================

# Set the version of Eclipse CDT you are using.
# Eclipse versions: 2019-12 (4.14), 2019-09 (4.13), 2019-06 (4.12), 2019-03 (4.11), 2018-12 (4.10), 2018-09 (4.9), Photon (4.8), Oxygen (4.7), Neon (4.6), Mars (4.5)
eclipseCdtVersion="4.14"
# Set the current directory as the 'original' directory.
originalDir=$PWD
# Log level - Possible values <ERROR|WARNING|NOTICE|STATUS|VERBOSE|DEBUG|TRACE>
logLevel="DEBUG"
# Address model - List with possible values <32|64>, e.g. "32 64"
# NOTE: CentOS 8 is not yet ported to the i686 architecture, 32bit won't work.
addressModel="64"
# Processor Architecture - Lst with possible values <x86|ARM>, e.g. "x86 ARM"
targetProcessorArchitecture="x86"
# Build types - List with possible values <None|Debug|Release|RelWithDebInfo|MinSizeRel>, e.g. "Debug Release RelWithDebInfo"
buildTypes="Debug Release"
# Set the build folder
baseBuildFolder="../build/eclipse_unix"

# ----------------------------------------------------------------------
# Generate arguments for CMAKE using the set values from the previous
# section.
# ----------------------------------------------------------------------
if [ ! -z "${logLevel:+x}" ] 
then
	# Generate the log level argument.
	cmakeLogLevel="--loglevel=${logLevel}"
fi

# ======================================================================
# Create a project for Eclipse CDT
# ======================================================================

# Inform the user
echo "==========================================================================================="
echo "Building project(s) for Eclipse CDT version $eclipseCdtVersion"
echo "==========================================================================================="

# Go into the source folder.
cd ../../sources

# Create Eclipse CDT projects for different address models, target processors and build types.
for iteratedAddressModel in ${addressModel}; do
	for iteratedTargetProcessorArchitecture in $targetProcessorArchitecture; do

		# Create the target architecture and model identifier.
		if [ ${iteratedTargetProcessorArchitecture} = "x86" ]; then
			if [ ${iteratedAddressModel} = "32" ]; then
				targetArchitectureAndModel="x86"
			else
				targetArchitectureAndModel="amd64"
			fi
		else 
			if [ ${iteratedAddressModel} = "32" ]; then
				targetArchitectureAndModel="arm"
			else
				targetArchitectureAndModel="arm64"	
			fi		
		fi

		# Set the correct toolchain file.
		cmakeToolchainFile="-DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/linux/${targetArchitectureAndModel}.toolchain"

		for iteratedBuildType in $buildTypes; do
			echo "Building '$iteratedBuildType' project for a ${iteratedAddressModel}bit '${iteratedTargetProcessorArchitecture}' processor."
			echo "-------------------------------------------------------------------------------------------"
						
			# Generate the build type argument.
			cmakeBuildType="-DCMAKE_BUILD_TYPE=${iteratedBuildType}"
			# Append subfolder.
			buildFolder="${baseBuildFolder}_${iteratedBuildType}/${targetArchitectureAndModel}"

			cmake -B${buildFolder} -G"Eclipse CDT4 - Unix Makefiles" -D_ECLIPSE_VERSION=${eclipseCdtVersion} ${cmakeToolchainFile} ${cmakeLogLevel} ${cmakeBuildType}

			# Inform the user
			echo "-------------------------------------------------------------------------------------------"
			echo "Done building. Import the Eclipse project from the subfolder \"$buildFolder\"!"
			echo "-------------------------------------------------------------------------------------------"
		done	
	done
done


# Return to the original folder.
echo "Returning to original directory."
cd "$originalDir"

# Keep the window open for 5 seconds
# read -rsp $'Press any key or wait 5 seconds to continue...\n' -n 1 -t 5
