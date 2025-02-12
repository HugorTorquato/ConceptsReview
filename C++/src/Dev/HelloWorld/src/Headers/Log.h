// #pragma once // Header guarder, that makes sure to include this file only once in a file
// just in a single cpp file, not at several files
// can cause a significant failure because it could duplicate structures or other definitions
#ifndef LOG_H
#define LOG_H

void Logr(const char* message);
void InitLog();


// class to write message to the console and log levels
class Log
{
    // Separate the public members
    public:
        enum Level
        {
            LevelError, LevelWarning, LevelInfo
        };

        // const int LogLevelError = 0;
        // const int LogLevelWarning = 1;
        // const int LogLevelInfo = 2;

    private:
        // Private member variable
        // Restrict the code to return just the allowed values
        Level m_LogLevel = Level::LevelInfo;

    public:
        void SetLevel(Level level);
        // can't have a conflict name
        void error(const char* message );
        void warn(const char* message );
        void info(const char* message );
};

#endif