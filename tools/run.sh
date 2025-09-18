#!/usr/bin/env bash
set -e

OS=$(uname | tr '[:upper:]' '[:lower:]')
if [[ "$OS" == "darwin" ]]; then
    OS="mac"
fi

EXE="build/$OS/hanabi"

if [[ ! -x "$EXE" ]]; then
    echo "[ERROR] Executable not found: $EXE"
    echo "Build first with ./tools/build_all.sh"
    exit 1
fi

echo "[INFO] Running hanabi..."
"$EXE"
