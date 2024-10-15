cmake_minimum_required(VERSION 3.30)

project(OLAS VERSION 1.2)

configure_file(OLASConfig.h.in OLASConfig.h)

add_executable(${PROJECT_NAME} main.cpp)

# include the output binary code as a include directory because we will put the verson in there. So it needs to know where to look
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})


####### DOWNLOAD ALL SUBMODULES

#find_package(Git QUIET)
#if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/../../.git")
## Update submodules as needed
#    option(GIT_SUBMODULE "Check submodules during build" ON)
#    if(GIT_SUBMODULE)
#        message(STATUS "submodules update")
#        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
#                        WORKING_DIRECTORY $CMAKE_CURRENT_SOURCE_DIR
#                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
#        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
#            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please check")
#        endif()
#    endif()
#endif()

###############################


add_subdirectory(Adder)
add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
    PUBLIC Adder
    PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE Adder
    PRIVATE external/glfw/src
)

target_link_libraries(${PROJECT_NAME} 
    Adder
    glfw
)