cmake_minimum_required(VERSION 3.5)

project(HelloWorld)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set source directory
set(source_dir "${PROJECT_SOURCE_DIR}/src/")
message(STATUS "Source directory: ${source_dir}")

# Find all source files
file(GLOB source_files "${source_dir}/*.cpp")

# Ensure source files are found
if(NOT source_files)
    message(FATAL_ERROR "No source files found in ${source_dir}")
endif()

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/Headers)

# Define the executable
add_executable(HelloWorld ${source_files})

# Add compile options (preferred way)
target_compile_options(HelloWorld PRIVATE -Wall -Werror)