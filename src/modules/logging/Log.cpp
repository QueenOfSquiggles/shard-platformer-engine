#include "Log.hpp"
namespace logging
{

    Log::Log(string name)
    {
        this->name = name;
    }

    void Log::log(string text)
    {
        #ifdef DEBUG       
        print(text, logColour);
        #endif
    }

    void Log::err(string text)
    {
        print(text, errColour);
    }

    void Log::warn(string text)
    {
        print(text, warningColour);
    }

    void Log::debug(string text)
    {
        #ifdef DEBUG
        print(text, debugColour);
        #endif
    }


    void Log::print(string text, string colour)
    {
        std::cout << colour << "[" << name << "] " << text << LOG_COL_RESET << std::endl;
    }

    void Log::raylibLogCallback(int msgType, const char* text, va_list args)
    {
        string message = "";
        switch(msgType)
        {
            case LOG_INFO: message += "[INFO]"; break;
            case LOG_ERROR: message += "[ERROR]"; break;
            case LOG_WARNING: message += "[WARNING]"; break;
            case LOG_DEBUG: message += "[DEBUG]"; break;
            default: message += "[OTHER]"; break;
        }
        //message += " " + string(text);

        // get the va_list to string

        string argStr;
        va_list tempCopy;
        va_copy(tempCopy, args);
        size_t len = vsnprintf(0, 0, text, tempCopy);
        argStr.resize(len+1);
        vsnprintf(&argStr[0], len+1, text, args);
        argStr.resize(len);

        message += argStr; // argStr should not be concat of 'message' and 'args'

        switch(msgType)
        {
            case LOG_ERROR: err(message); break;
            case LOG_WARNING: warn(message); break;
            case LOG_DEBUG: debug(message); break;
            // all else use default log
            default: log(message); break;
        }

    }


}
