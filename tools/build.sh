#!/usr/bin/env bash
set -e

# Detect OS folder
OS=$(uname | tr '[:upper:]' '[:lower:]')
if [[ "$OS" == "darwin" ]]; then
    OS="mac"
elif [[ "$OS" == *"mingw"* || "$OS" == *"msys"* ]]; then
    OS="win64"
fi

# Find script dir and project root
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
BUILD_DIR="$PROJECT_ROOT/build/$OS"
EXE_NAME="hanabi"

# CPU cores
if command -v nproc >/dev/null 2>&1; then
    CORES=$(nproc)
elif command -v sysctl >/dev/null 2>&1; then
    CORES=$(sysctl -n hw.ncpu)
else
    CORES=4
fi

# Clean
if [[ "$1" == "clean" ]]; then
    echo "[INFO] Cleaning build..."
    rm -rf "$BUILD_DIR"
    echo "[INFO] Clean finished. Exiting."
    exit 0
fi

# Build
echo "[INFO] Building in $BUILD_DIR..."
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"
cmake "$PROJECT_ROOT" -DCMAKE_BUILD_TYPE=Debug
cmake --build . --parallel "$CORES"
cd -

echo "[INFO] Done. Executable is at $BUILD_DIR/$EXE_NAME"
