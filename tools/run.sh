#!/usr/bin/env bash
set -e

FRONTEND=${1:-ascii}  # default to ascii

OS=$(uname | tr '[:upper:]' '[:lower:]')
if [[ "$OS" == "darwin" ]]; then
    OS="mac"
fi

EXE="build/$OS/$FRONTEND/hanabi"

if [[ ! -x "$EXE" ]]; then
    echo "[ERROR] Executable not found: $EXE"
    echo "Build first with ./tools/build_all.sh"
    exit 1
fi

echo "[INFO] Running $FRONTEND frontend..."
"$EXE"
