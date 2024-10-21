
# Add library for the main project


if(NOT TARGET HashTablesLib)
    add_library(HashTablesLib src/HashTables.cpp)
endif()

# Include directory for headers
target_include_directories(HashTablesLib PUBLIC ${CMAKE_SOURCE_DIR}/src/HashTable/include)