
# Add library for the main project


if(NOT TARGET LlinkedListsLib)
    add_library(LlinkedListsLib src/LlinkedLists.cpp)
endif()

# Include directory for headers
target_include_directories(LlinkedListsLib PUBLIC ${CMAKE_SOURCE_DIR}/src/LlinkedLists/include)