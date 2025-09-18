@echo off
setlocal

set OS=windows
set EXE=build\%OS%\hanabi.exe

if not exist "%EXE%" (
    echo [ERROR] Executable not found: %EXE%
    echo Build first with tools\build_all.bat
    exit /b 1
)

echo [INFO] Running hanabi...
"%EXE%"

endlocal
