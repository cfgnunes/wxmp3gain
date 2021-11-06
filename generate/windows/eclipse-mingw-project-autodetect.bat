@echo off
REM ======================================================================
REM Setup
REM ======================================================================

REM Set the version of Eclipse CDT you are using.
REM Eclipse versions: 2019-09 (4.13), 2019-06 (4.12), 2019-03 (4.11), 2018-12 (4.10), 2018-09 (4.9), Photon (4.8), Oxygen (4.7), Neon (4.6), Mars (4.5)
set eclipseCdtVersion=4.13
set originalDir=%cd%

REM ======================================================================
REM Create a project for Eclipse CDT
REM ======================================================================

REM Inform the user
echo ===========================================================================================
echo Building a project for Eclipse CDT version %eclipseCdtVersion% (Edit batch file to change version)
echo ===========================================================================================

REM Go into the source folder.
cd ../../sources

REM Create a Eclipse CDT project.
cmake -B../build/eclipse_win_autodetect -G"Eclipse CDT4 - MinGW Makefiles" -D_ECLIPSE_VERSION=%eclipseCdtVersion%

REM Return to the original folder.
echo Returning to original directory.
cd "%originalDir%"

REM Inform the user
echo ===========================================================================================
echo Done building. Import the Eclipse project from the subfolder "build/eclipse/autodetect"!
echo ===========================================================================================

REM Wait 5 seconds
REM timeout 5
PAUSE
