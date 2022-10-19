#!/usr/bin/env bash
cd "$(dirname "$0")/../"
mkdir -p build
cmake .
make
cd extensions/aa
cmake .
make
cd ../../
mv profcont extensions/**/*.dylib build/
git clean -df