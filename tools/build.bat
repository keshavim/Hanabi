@echo off
setlocal

set OS=windows
set BUILD_DIR=build\%OS%

if "%1"=="clean" (
    echo [INFO] Cleaning build...
    rmdir /s /q "%BUILD_DIR%"
    echo [INFO] Clean finished. Exiting.
    exit /b 0
)

if not exist %BUILD_DIR% (
    mkdir %BUILD_DIR%
)

cd %BUILD_DIR%

echo [INFO] Configuring project...
cmake ..\.. -DCMAKE_BUILD_TYPE=Debug -DBUILD_SFML=OFF

echo [INFO] Building project...
cmake --build . --config Debug

echo [INFO] Done. Executable is at %BUILD_DIR%\hanabi.exe

endlocal
