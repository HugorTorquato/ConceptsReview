cmake_minimum_required(VERSION 3.13)

project(testAdd)

add_executable(testAdd cpp/main.cpp)

target_link_directories(testAdd PRIVATE "../SomeLibDemo/build/linux")

target_link_libraries(testAdd mearlymath)

