
# Add library for the main project


if(NOT TARGET StacksLib)
    add_library(StacksLib src/Stacks.cpp)
endif()

# Include directory for headers
target_include_directories(StacksLib PUBLIC ${CMAKE_SOURCE_DIR}/src/Stacks/include)