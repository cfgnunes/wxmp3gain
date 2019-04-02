@echo off
cls

set APP_NAME=wxmp3gain
set OUTPUT_DIR=build

echo Starting %APP_NAME% build...
if exist %OUTPUT_DIR% rmdir %OUTPUT_DIR% /s /q
mkdir %OUTPUT_DIR%\resource
echo Done!
echo.

echo Removing previous build...
if exist *.o del *.o /q /f /a
if exist *.res del *.res /q /f /a
echo Done!
echo.

echo Compiling project...
mingw32-g++.exe -pipe -mthreads -D__GNUWIN32__ -D__WXMSW__ -DWXUSINGDLL -DwxUSE_UNICODE -Wno-attributes -ansi -Wall -O2 -IC:\TDM-GCC-32\include -IC:\TDM-GCC-32\lib\gcc510TDM_dll\mswu -c ..\src\*.cpp
echo Done!
echo.

echo Compiling resource file...
windres.exe -IC:\TDM-GCC-32\include -IC:\TDM-GCC-32\lib\gcc510TDM_dll\mswu -J rc -O coff -i resource.rc -o resource.res
echo Done!
echo.

echo Linking objects...
mingw32-g++.exe -LC:\TDM-GCC-32\lib\gcc510TDM_dll -o %OUTPUT_DIR%\%APP_NAME%.exe *.o resource.res -s -mthreads -lwxbase31u -lwxbase31u_net -lwxbase31u_xml -lwxexpat -lwxjpeg -lwxmsw31u_adv -lwxmsw31u_aui -lwxmsw31u_core -lwxmsw31u_gl -lwxmsw31u_html -lwxmsw31u_media -lwxmsw31u_propgrid -lwxmsw31u_ribbon -lwxmsw31u_richtext -lwxmsw31u_stc -lwxmsw31u_webview -lwxmsw31u_xrc -lwxpng -lwxregexu -lwxscintilla -lwxtiff -lwxzlib -mwindows
echo Done!
echo.

echo Copying files to "%OUTPUT_DIR%" directory...
xcopy /h /e /f "..\resource\*" "%OUTPUT_DIR%\resource\"
copy /y "%APP_NAME%.exe" "%OUTPUT_DIR%\"
copy /y "C:\TDM-GCC-32\lib\gcc510TDM_dll\wxbase312u_gcc510TDM.dll" "%OUTPUT_DIR%\"
copy /y "C:\TDM-GCC-32\lib\gcc510TDM_dll\wxmsw312u_core_gcc510TDM.dll" "%OUTPUT_DIR%\"
copy "..\docs\COPYING" "%OUTPUT_DIR%\License.txt"
copy "..\docs\CHANGELOG" "%OUTPUT_DIR%\Changelog.txt"
copy "..\docs\README" "%OUTPUT_DIR%\Readme.txt"
echo Done!
echo.

echo Stripping binaries...
strip -s %OUTPUT_DIR%\*.exe
strip -s %OUTPUT_DIR%\*.dll
echo Done!
echo.

echo Compiling translation files...
for %%L in (cs,de,es,hr_HR,pt_BR,ru,tr) do (
	mkdir build\resource\msg\%%L\
	msgfmt ..\msg\%%L.po -o build\resource\msg\%%L\%APP_NAME%.mo
	)
echo Done!
echo.

pause
