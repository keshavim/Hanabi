#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Launch new GNOME Terminal and run run.sh becuse i don't now how to do external terminal in clion
gnome-terminal -- bash -c "$SCRIPT_DIR/run.sh; exec bash"
