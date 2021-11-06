@echo off
SETLOCAL ENABLEDELAYEDEXPANSION
REM ======================================================================
REM Setup
REM ======================================================================
REM Set the current directory as the 'original' directory.
set originalDir=%cd%
REM Log level - Possible values <ERROR|WARNING|NOTICE|STATUS|VERBOSE|DEBUG|TRACE>
set "logLevel=STATUS"
REM Address model - Comma separated list with possible values <32|64>, e.g. "32,64"
set "addressModel=64"
REM Processor Architecture - Comma separated list with possible values <x86|ARM>, e.g. "x86,ARM"
set "targetProcessorArchitecture=x86"
REM Build types - Comma separated list with possible values <None|Debug|Release|RelWithDebInfo|MinSizeRel>, e.g. "Debug,Release,RelWithDebInfo"
set "buildTypes=Debug,Release"
REM Set the build folder
set "buildFolder=../build/mingw_makefiles"

REM ----------------------------------------------------------------------
REM Generate arguments for CMAKE using the set values from the previous
REM section.
REM ----------------------------------------------------------------------

if defined logLevel (
	REM Generate the log level argument.
	set "cmakeLogLevel=--loglevel=%logLevel%"
)

REM ======================================================================
REM Create a project for MinGW Makefiles
REM ======================================================================

REM Inform the user
echo ===========================================================================================
echo Building a project for MinGW Makefiles
echo ===========================================================================================

REM Go into the source folder.
cd ../../sources

REM Create a MinGW Makefile projects for different address models and build types.
for %%a in ("%addressModel:,=" "%") do (
	set "iteratedAddressModel=%%~a"
	REM Set the correct toolchain file.
	set "cmakeToolchainFile=-DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/windows/mingw!iteratedAddressModel!.toolchain"
	
	for %%p in ("%targetProcessorArchitecture:,=" "%") do (
		set "iteratedTargetProcessorArchitecture=%%~p"	
		
		REM Create the target architecture and model identifier.
		if !iteratedTargetProcessorArchitecture! == x86 (
			if !iteratedAddressModel! == 32 (
				set "targetArchitectureAndModel=x86"
			) else (
				set "targetArchitectureAndModel=amd64"
			)
		) else (
			if !iteratedAddressModel! == 32 (
				set "targetArchitectureAndModel=arm"
			) else (
				set "targetArchitectureAndModel=arm64"
			)
		)
		
		for %%b in ("%buildTypes:,=" "%") do (
			set "iteratedBuildType=%%~b"
			echo Building '!iteratedBuildType!' project for a !iteratedAddressModel!bit '!iteratedTargetProcessorArchitecture!' processor.
			echo -------------------------------------------------------------------------------------------
			
			REM Generate the build type argument.
			set "cmakeBuildType=-DCMAKE_BUILD_TYPE=!iteratedBuildType!"
			REM Append subfolder.
			set "buildFolder=%buildFolder%_!iteratedBuildType!/!targetArchitectureAndModel!"
			
			cmake -B!buildFolder! -G"MinGW Makefiles" !cmakeToolchainFile! %cmakeLogLevel% !cmakeBuildType!
			
			REM Inform the user
			echo -------------------------------------------------------------------------------------------
			echo Done creating makefiles in the subfolder "!buildFolder!"!
			echo -------------------------------------------------------------------------------------------
		)
	)
)

REM Return to the original folder.
echo Returning to original directory.
cd "%originalDir%"

REM Wait 5 seconds
REM timeout 5
PAUSE

