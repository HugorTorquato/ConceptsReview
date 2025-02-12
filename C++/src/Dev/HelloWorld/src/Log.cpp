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

void Log::SetLevel(int level)
{

}

void Log::error(const char* message )
{
    if (m_LogLevel >= LogLevelError)
        std::cout << "[ERROR]: " << message << std::endl;
}

void Log::warn(const char* message )
{
    if (m_LogLevel >= LogLevelWarning)
        std::cout << "[WARNING]: " << message << std::endl;
}

void Log::info(const char* message )
{
    if (m_LogLevel >= LogLevelInfo)
        std::cout << "[INFO]: " << message << std::endl;
}

