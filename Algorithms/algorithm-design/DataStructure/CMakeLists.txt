cmake_minimum_required(VERSION 3.10)

project(DataStructure)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source and test subdirectories
add_subdirectory(src)   # Main project source
add_subdirectory(tests) # Unit tests

# Enable testing
enable_testing()