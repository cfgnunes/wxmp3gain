@echo off
SETLOCAL ENABLEDELAYEDEXPANSION
REM ======================================================================
REM Setup
REM ======================================================================

REM Set the version of Visual Studio you are using.
REM https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html#visual-studio-generators
REM Visual Studio versions: 2019 (16), 2017 (15), 2015 (14), 2013 (12), 2012 (11), etc.
REM NOTE: Minimum version is "Visual Studio 9 2008"
set visualStudioVersion=16
REM Set the current directory as the 'original' directory.
set originalDir=%cd%
REM Address model - Comma separated list with possible values <32|64>, e.g. "32,64"
set "addressModel=64"
REM Processor Architecture - Comma separated list with possible values <x86|ARM>, e.g. "x86,ARM"
set "targetProcessorArchitecture=x86"
REM Build shared libraries.
set "buildSharedLibraries=false"
REM Optionally define linkage type to the C/C++ Runtime Library.
REM See https://cmake.org/cmake/help/latest/variable/CMAKE_MSVC_RUNTIME_LIBRARY.html
REM See https://docs.microsoft.com/en-us/cpp/build/reference/md-mt-ld-use-run-time-library?view=msvc-160
REM Possible values: <MultiThreaded|MultiThreadedDLL|MultiThreadedDebug|MultiThreadedDebugDLL>
REM set "vcppRuntimeLibraryLinkage=MultiThreaded"

REM Possible values <ERROR|WARNING|NOTICE|STATUS|VERBOSE|DEBUG|TRACE>
set "logLevel=DEBUG"

REM ----------------------------------------------------------------------
REM Generate arguments for CMAKE using the set values from the previous
REM section.
REM ----------------------------------------------------------------------
if defined vcppRuntimeLibraryLinkage (
    set "cmakeMsvcRuntimeLibrary=-DCMAKE_MSVC_RUNTIME_LIBRARY="%vcppRuntimeLibraryLinkage%""
)

if defined logLevel (
	REM Generate the log level argument.
	set "cmakeLogLevel=--loglevel=%logLevel%"
)

REM Generate project folder name, depending on the Visual Studio version.
if %visualStudioVersion% == 16 (
	set projectFolder=msvs2019
	set "generatorName=Visual Studio 16 2019"
)
if %visualStudioVersion% == 15 (
	set projectFolder=msvs2017
	set "generatorName=Visual Studio 15 2017"
)
if %visualStudioVersion% == 14 (
	set projectFolder=msvs2015
	set "generatorName=Visual Studio 14 2015"
)
if %visualStudioVersion% == 12 (
	set projectFolder=msvs2013
	set "generatorName=Visual Studio 12 2013"
)
if %visualStudioVersion% == 11 (
	set projectFolder=msvs2012
	set "generatorName=Visual Studio 11 2012"
)
if %visualStudioVersion% == 10 (
	set projectFolder=msvs2010
	set "generatorName=Visual Studio 10 2010"
)
if %visualStudioVersion% == 9 (
	set projectFolder=msvs2008
	set "generatorName=Visual Studio 9 2008"
)

REM Set the build folder
set "buildFolder=../build/%projectFolder%"

REM ======================================================================
REM Create a project for Visual Studio
REM ======================================================================

REM Inform the user
echo ===========================================================================================
echo Building projects for %generatorName%
echo ===========================================================================================

REM Go into the source folder.
cd ../../sources

REM Create a Visual Studio projects for different adress models and processor architectures.
for %%a in ("%addressModel:,=" "%") do (
	set "iteratedAddressModel=%%~a"
	
	for %%p in ("%targetProcessorArchitecture:,=" "%") do (
		set "iteratedTargetProcessorArchitecture=%%~p"		
		echo Building project for a !iteratedAddressModel!bit '!iteratedTargetProcessorArchitecture!' processor.
		echo -------------------------------------------------------------------------------------------
		
		REM Create the target architecture and model identifier.
		if !iteratedTargetProcessorArchitecture! == x86 (
			if !iteratedAddressModel! == 32 (
				set "targetArchitectureAndModel=x86"
				set "targetArchitectureAndModelMsvs=Win32"
			) else (
				set "targetArchitectureAndModel=amd64"
				set "targetArchitectureAndModelMsvs=x64"
			)
		) else (
			if !iteratedAddressModel! == 32 (
				set "targetArchitectureAndModel=arm"
				set "targetArchitectureAndModelMsvs=ARM"
			) else (
				set "targetArchitectureAndModel=arm64"
				set "targetArchitectureAndModelMsvs=ARM64"
			)
		)

		REM Append subfolder.
		set "buildFolder=%buildFolder%_!targetArchitectureAndModel!"

		REM Potentially append MSVC linkage type to runtime library.
		if defined vcppRuntimeLibraryLinkage (	
			if !vcppRuntimeLibraryLinkage! == MultiThreaded (
				set "buildFolder=!buildFolder!_MT"
			)
			if !vcppRuntimeLibraryLinkage! == MultiThreadedDLL (
				set "buildFolder=!buildFolder!_MD"
			)
			if !vcppRuntimeLibraryLinkage! == MultiThreadedDebug (
				set "buildFolder=!buildFolder!_MTd"
			)
			if !vcppRuntimeLibraryLinkage! == MultiThreadedDebugDLL (
				set "buildFolder=!buildFolder!_MDd"
			)
        )

		cmake -B!buildFolder! -G"%generatorName%" -A !targetArchitectureAndModelMsvs! %cmakeLogLevel% -DBUILD_SHARED_LIBS=%buildSharedLibraries% %cmakeMsvcRuntimeLibrary%
		
		REM Inform the user
		echo -------------------------------------------------------------------------------------------
		echo Done building. Open the VS solution file ^(.sln^) in the "!buildFolder!"!
		echo -------------------------------------------------------------------------------------------
	)
)

REM Return to the original folder.
echo Returning to original directory.
cd "%originalDir%"

REM Wait 5 seconds
REM timeout 5
PAUSE
