@echo off
setlocal

set OS=windows
set BUILD_DIR=build\%OS%

if "%1"=="clean" (
    echo [INFO] Cleaning build...
    rmdir /s /q %BUILD_DIR%
)

if not exist %BUILD_DIR% (
    mkdir %BUILD_DIR%
)

cd %BUILD_DIR%

echo [INFO] Configuring for %OS%...
cmake ..\.. -DCMAKE_BUILD_TYPE=Debug -DBUILD_ASCII=ON -DBUILD_SFML=ON

echo [INFO] Building project...
cmake --build . --config Debug

echo [INFO] Done. Executables are under build\%OS%\frontend\hanabi.exe

endlocal
