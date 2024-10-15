#include <iostream>
#include "glfw/glfw3.h"
#include "OLASConfig.h"

#ifdef USE_ADDER
    #include "Adder/adder.h"
#endif

int main(int argc, char* argv[]) {
    std::cout << "Hey Budy " << std::endl;

#ifdef USE_ADDER
    // In case this is set to OFF will not compile this. 
    // Otherwise it is already included in the .h file
    std::cout << "2 + 3 = " << mearlymath::add(2, 3) << std::endl;
#else
    std::cout << "2 + 3 = " << "6" << std::endl;
#endif

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