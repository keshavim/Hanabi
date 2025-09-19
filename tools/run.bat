@echo off
setlocal enabledelayedexpansion

set OS=win64
set SCRIPT_DIR=%~dp0
set PROJECT_ROOT=%SCRIPT_DIR%\..
set BUILD_DIR=%PROJECT_ROOT%\build\%OS%
set EXE=%BUILD_DIR%\hanabi.exe

:: Build first
call %SCRIPT_DIR%\build.bat

:: Run
if not exist "%EXE%" (
    echo [ERROR] Executable not found: %EXE%
    exit /b 1
)

echo [INFO] Running hanabi...
"%EXE%"

endlocal
