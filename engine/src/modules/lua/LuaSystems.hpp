#pragma once

extern "C"
{
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

#include <string>
#include "../logging/Log.hpp"

namespace lua
{
    class LuaManager
    {

        lua_State* currentState = nullptr;
        logging::Log log = logging::Log("Lua");

        void pushLuaError();
        int runWithErrCheck(int errCode);
        const char* get_cstr_from_state(int index);
        double get_double_from_state(int index);
        int get_int_from_state(int index);

        public:
            void createNewState(bool openLibs);
            void registerMethod(string methodName, lua_CFunction func);
            int loadFile(string filePath);
            int executeState();
            int callLuaMethod(string method);
            int executeLuaString(string luaCode);
            void close();
        
    };
}
