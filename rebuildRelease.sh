#!/usr/bin/env bash
set -euxo pipefail

cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -G Ninja
cmake --build build --parallel 