#include "Log.hpp"
namespace logging
{

    Log::Log(string name)
    {
        this->name = name;
    }

    void Log::log(string text)
    {
        print(text, logColour);
    }

    void Log::err(string text)
    {
        print(text, errColour);
    }

    void Log::warn(string text)
    {
        print(text, warningColour);
    }

    void Log::print(string text, string colour)
    {
        std::cout << colour << "[ " << name << " ] \t" << text << LOG_COL_RESET << std::endl;
    }
}
