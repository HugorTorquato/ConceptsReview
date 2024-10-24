
# Add library for the main project


if(NOT TARGET GraphsLib)
    add_library(GraphsLib src/Graphs.cpp)
endif()

# Include directory for headers
target_include_directories(GraphsLib PUBLIC ${CMAKE_SOURCE_DIR}/src/Graphs/include)