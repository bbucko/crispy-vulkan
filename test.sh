#!/bin/bash
BUILD_DIR=build-$1
cd $BUILD_DIR
echo "Starting tests"
make test
echo "Tests done"