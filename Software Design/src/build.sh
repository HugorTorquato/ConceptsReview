#!/bin/sh

cmake -S . -B ./build -G "Unix Makefiles" -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug
