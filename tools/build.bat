@echo off
setlocal enabledelayedexpansion

:: Detect OS
set OS=win64

:: Find project root (parent of script dir)
set SCRIPT_DIR=%~dp0
set PROJECT_ROOT=%SCRIPT_DIR%\..
set BUILD_DIR=%PROJECT_ROOT%\build\%OS%
set EXE_NAME=hanabi.exe

:: Clean
if "%1"=="clean" (
    echo [INFO] Cleaning build...
    rmdir /s /q "%BUILD_DIR%" 2>nul
    echo [INFO] Clean finished. Exiting.
    exit /b 0
)

:: Build
echo [INFO] Building in %BUILD_DIR%...
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"
pushd "%BUILD_DIR%"
cmake "%PROJECT_ROOT%" -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
popd

echo [INFO] Done. Executable is at %BUILD_DIR%\%EXE_NAME%
endlocal
