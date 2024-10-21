
# Add library for the main project


if(NOT TARGET QueuesLib)
    add_library(QueuesLib src/Queues.cpp)
endif()

# Include directory for headers
target_include_directories(QueuesLib PUBLIC ${CMAKE_SOURCE_DIR}/src/Queues/include)