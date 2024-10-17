
# Add library for the main project


if(NOT TARGET VectorLib)
    add_library(VectorLib src/Vectors.cpp)
endif()

# Include directory for headers
target_include_directories(VectorLib PUBLIC ${CMAKE_SOURCE_DIR}/src/Vectors/include)