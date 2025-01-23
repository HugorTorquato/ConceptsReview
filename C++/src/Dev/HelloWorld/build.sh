#!/bin/sh

cmake -S . -B ./out/build -G "Unix Makefiles" -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug
