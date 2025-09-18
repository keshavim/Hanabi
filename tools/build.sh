#!/usr/bin/env bash
set -e

# OS folder
OS=$(uname | tr '[:upper:]' '[:lower:]')
if [[ "$OS" == "darwin" ]]; then
    OS="mac"
fi

BUILD_DIR="build/$OS"

# CPU cores
if command -v nproc >/dev/null 2>&1; then
    CORES=$(nproc)
elif command -v sysctl >/dev/null 2>&1; then
    CORES=$(sysctl -n hw.ncpu)
else
    CORES=4
fi

# Clean build
if [[ "$1" == "clean" ]]; then
    echo "[INFO] Cleaning build..."
    rm -rf "$BUILD_DIR"
    echo "[INFO] Clean finished. Exiting."
    exit 0
fi
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

echo "[INFO] Configuring project..."
cmake ../.. -DCMAKE_BUILD_TYPE=Debug -DBUILD_SFML=OFF

echo "[INFO] Building..."
cmake --build . --parallel "$CORES"

echo "[INFO] Done. Executable is at $BUILD_DIR/hanabi"
