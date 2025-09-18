@echo off
setlocal

set FRONTEND=%1
if "%FRONTEND%"=="" set FRONTEND=ascii

set EXE=build\windows\%FRONTEND%\hanabi.exe

if not exist "%EXE%" (
    echo [ERROR] Executable not found: %EXE%
    echo Build first with tools\build_all.bat
    exit /b 1
)

echo [INFO] Running %FRONTEND% frontend...
"%EXE%"
