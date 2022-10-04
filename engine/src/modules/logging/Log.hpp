#pragma once
#include <iostream>
#include <string>

#define LOG_COL_BLACK "\033[30m"
#define LOG_COL_BLACK_BOLD "\033[1;30m"
#define LOG_COL_RED "\033[31m"
#define LOG_COL_RED_BOLD "\033[1;31m"
#define LOG_COL_GREEN "\033[32m"
#define LOG_COL_GREEN_BOLD "\033[1;32m"
#define LOG_COL_YELLOW "\033[33m"
#define LOG_COL_YELLOW_BOLD "\033[1;33m"
#define LOG_COL_BLUE "\033[34m"
#define LOG_COL_BLUE_BOLD "\033[1;34m"
#define LOG_COL_MAGENTA "\033[35m"
#define LOG_COL_MAGENTA_BOLD "\033[1;35m"
#define LOG_COL_CYAN "\033[36m"
#define LOG_COL_CYAN_BOLD "\033[1;36m"
#define LOG_COL_WHITE "\033[37m"
#define LOG_COL_WHITE_BOLD "\033[1;37m"

#define LOG_COL_RESET "\033[0m"

using namespace std;

namespace logging
{
    class Log
    {
        string errColour = LOG_COL_RED_BOLD;
        string warningColour = LOG_COL_YELLOW_BOLD;
        string logColour = LOG_COL_BLUE; 
        string name = "DefaultLogger";

    public:
        Log(string name);

        void log(string text);
        void err(string text);
        void warn(string text);
        void print(string text, string colour);
    };
}