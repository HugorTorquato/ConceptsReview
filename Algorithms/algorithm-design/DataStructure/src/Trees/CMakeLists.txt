
# Add library for the main project


if(NOT TARGET TreesLib)
    add_library(TreesLib src/Trees.cpp)
endif()

# Include directory for headers
target_include_directories(TreesLib PUBLIC ${CMAKE_SOURCE_DIR}/src/Trees/include)