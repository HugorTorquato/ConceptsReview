# Declare a dependency on GoogleTest. This is a standard definition to start
# projects running unit tests with gtests


# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(DOWNLOAD_EXTRACT_TIMESTAMP FALSE)
cmake_policy(SET CMP0076 NEW)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
  )
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

# Add the unit test executable
add_executable(UnitTests
    ArrayTests.cpp
)

# Link the unit tests with GoogleTest and the main project library
target_link_libraries( UnitTests PRIVATE
    GTest::GTest
    ArrayLib
    VectorLib
    LlinkedListsLib
    StacksLib
    QueuesLib
    HashTablesLib
)

target_sources(UnitTests PUBLIC
    # Add new files with unit tests definitions here
    ArrayTests.cpp 
    VectorTests.cpp 
    LlinkedListsTests.cpp 
    StacksTests.cpp 
    QueuesTests.cpp 
    HashTablesTests.cpp 
)

include(GoogleTest)
gtest_discover_tests(UnitTests)