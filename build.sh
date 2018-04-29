#!/bin/bash
BUILD_DIR=build-$1
mkdir $BUILD_DIR
cd $BUILD_DIR
cmake -DCMAKE_BUILD_TYPE=$1 ..
echo "Starting build"
make
echo "Build done"