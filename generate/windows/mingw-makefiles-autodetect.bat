@echo off
REM ======================================================================
REM Create the MinGW Make files.
REM ======================================================================

REM Inform the user
echo ===========================================================================================
echo Creating a MinGW Makefiles project
echo ===========================================================================================

REM Go into the source folder.
cd ../../sources

REM Create the MinGW makefiles.
cmake -B../build/mingw_makefiles_autodetect -G"MinGW Makefiles"

REM Return to the original folder.
echo Returning to original directory.
cd "%originalDir%"

REM Inform the user
echo ===========================================================================================
echo Done creating makefiles in the subfolder "build/mingw/autodetect".
echo ===========================================================================================

REM Wait 5 seconds
timeout 5
