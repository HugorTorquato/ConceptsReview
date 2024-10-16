
# Add library for the main project


if(NOT TARGET ArrayLib)
    add_library(ArrayLib src/Array.cpp)
endif()

# Include directory for headers
target_include_directories(ArrayLib PUBLIC ${CMAKE_SOURCE_DIR}/src/Arrays/include)