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
EXE="$BUILD_DIR/hanabi"

# Build first
"$SCRIPT_DIR/build.sh"

# Run
if [[ ! -x "$EXE" ]]; then
    echo "[ERROR] Executable not found: $EXE"
    exit 1
fi

echo "[INFO] Running hanabi..."
"$EXE"
