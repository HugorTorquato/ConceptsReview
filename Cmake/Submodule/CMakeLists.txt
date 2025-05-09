cmake_minimum_required(VERSION 3.30)

# Used to configure the Cmake version control. There is a commit with all this changes.
# Any value presented here can be used in the code as well based on major, minor and things like that
project(OLAS VERSION 1.2)

# include the adder lib as optional, in this case there is no need to import it

option(USE_ADDER "A simple library for adding 2 floats." OFF)


# Add the subdirectories with the libs we use. can be local ( as Adder ) or external one as ( external/glfw )
# in this case is better to put everything together

if(USE_ADDER)
    add_subdirectory(Adder)

    # Define it one by one
    #target_include_directories(${PROJECT_NAME} PUBLIC Adder)
    #target_link_directories(${PROJECT_NAME} PRIVATE Adder)
    #target_link_libraries(${PROJECT_NAME} Adder)

    #Define as a list to be smplier to add new optional libs
    # Only append to the list if using, otherwise it's blank
    list(APPEND EXTRA_LIBS Adder)
    list(APPEND EXTRA_INCLUDES Adder)
    list(APPEND EXTRA_LINK Adder)
    
endif()

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



add_subdirectory(external/glfw)

# Path to the include files to be used in the actuall code, the header files ( .h ).
# In the source code side, not the output build folder
target_include_directories(${PROJECT_NAME}
    #PUBLIC Adder
    PUBLIC external/glfw/include
    #{EXTRA_INCLUDES}
)

# This one looks at the lib output folder in BIN. This is the lib directory 
target_link_directories(${PROJECT_NAME} 
    #PRIVATE Adder
    PRIVATE external/glfw/src
    #{EXTRA_LIBS}
)

# Name of the lib to be used, without any prefix, sufix or extension.... Cmake will handle it as it is
# because it is diferent for linux mac and windows... so it needs to be generic at this point. Just the lib's name
target_link_libraries(${PROJECT_NAME} 
    #Adder
    glfw
    ${EXTRA_LINK}
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/OLASConfig.h" DESTINATION include)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${OLAS_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${OLAS_VERSION_MINOR}")
include(CPack)

