#!/usr/bin/env bash
set -e

# Detect OS folder name
OS=$(uname | tr '[:upper:]' '[:lower:]')
if [[ "$OS" == "darwin" ]]; then
    OS="mac"
fi

BUILD_DIR="build/$OS"

# Detect CPU cores
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
fi

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

#not using right now, switch to on when using
echo "[INFO] Configuring for $OS..."
cmake ../.. -DCMAKE_BUILD_TYPE=Debug -DBUILD_ASCII=ON -DBUILD_SFML=OFF

echo "[INFO] Building..."
cmake --build . --parallel "$CORES"

echo "[INFO] Done. Executables are under build/$OS/<frontend>/hanabi"
