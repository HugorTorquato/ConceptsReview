# CMakeList.txt : CMake project for DemoBase, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(vulkan REQUIRED)
#find_package(glad CONFIG REQUIRED)
#find_package(glfw3 CONFIG REQUIRED)

# Add source to this project's executable
add_executable(DemoBase "DemoBase.cpp" "DemoBase.h")

target_include_directories(C:/Projetos/ConceptsReview/Cmake/lib/externa/vulkan-sdk/include)

#target_link_libraries(DemoBase PRIVATE glm::glm glad::glad ${GLFW_LIBRARIES})
target_link_libraries(DemoBase PRIVATE ${VULKAN_LIBRARIES})

