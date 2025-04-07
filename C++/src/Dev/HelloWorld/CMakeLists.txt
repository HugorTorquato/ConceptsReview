cmake_minimum_required(VERSION 3.5)

project(HelloWorld)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GLFW static build
add_subdirectory(include/GLFW)

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

# Link GLFW statically
target_link_libraries(HelloWorld PRIVATE glfw)

# Required on Linux for linking X11 stuff
if (UNIX)
    target_link_libraries(HelloWorld PRIVATE dl pthread X11 Xrandr Xi Xxf86vm Xcursor GL)
endif()

# Include GLFW headers
target_include_directories(HelloWorld PRIVATE include/GLFW/include)