#include <iostream>
#include "Adder/adder.h"
#include "glfw/glfw3.h"
#include "OLASConfig.h"

int main(int argc, char* argv[]) {
    std::cout << "Hey Budy " << std::endl;
    std::cout << "2 + 3 = " << mearlymath::add(2, 3) << std::endl;

    std::cout << argv[0] << " Version: " << OLAS_VERSION_MAJOR << "." << OLAS_VERSION_MINOR << std::endl;

    GLFWwindow* window;

    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    // Main loop
    while( !glfwWindowShouldClose(window) )
    {

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}