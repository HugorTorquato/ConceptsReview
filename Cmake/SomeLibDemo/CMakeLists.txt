cmake_minimum_required(VERSION 3.30.5)

project(addLib)

add_library(mearlymath cpp/adder.cpp)

set_target_properties(mearlymath PROPERTIES PUBLIC_HEADER cpp/adder.h)

install (TARGETS mearlymath DESTINATION "/lib/"
    PUBLIC_HEADER DESTINATION "/include/")