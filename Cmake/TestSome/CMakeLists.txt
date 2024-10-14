cmake_minimum_required(VERSION 3.30)

project(testAdd)

add_executable(testAdd cpp/main.cpp)

target_link_directories(testAdd PRIVATE "/lib/")

target_link_libraries(testAdd mearlymath)

