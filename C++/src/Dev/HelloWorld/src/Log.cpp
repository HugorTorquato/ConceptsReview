#include "Log.h"
#include <iostream>

void Logr(const char* message) {
    std::cout << message << std::endl;
}

void InitLog() {
    std::cout << "Init Logs" << std::endl;
}

// This code is node valid
// void Logr(const char* message) {
//     std::cout << message << std::endl;
// }