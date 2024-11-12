
# Add library for the main project


if(NOT TARGET LambdaAndSTDFunctionsLib)
    add_library(LambdaAndSTDFunctionsLib src/LambdaAndSTDFunctions.cpp)
endif()

# Include directory for headers
target_include_directories(LambdaAndSTDFunctionsLib PUBLIC ${CMAKE_SOURCE_DIR}/src/LambdaAndSTDFunctions/include)