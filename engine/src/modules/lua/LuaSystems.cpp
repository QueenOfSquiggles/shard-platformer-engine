#include "LuaSystems.hpp"

namespace lua
{

    void LuaManager::pushLuaError()
    {
        string errorLog = lua_tostring(currentState, -1);
        log.err("Error:\t" + errorLog);
    }

    int LuaManager::runWithErrCheck(int errCode)
    {
        if (errCode) pushLuaError();
        return errCode;

    }


    const char* LuaManager::get_cstr_from_state(int index)
    {
        return lua_tostring(currentState, index);
    }

    double LuaManager::get_double_from_state(int index)
    {
        return lua_tonumber(currentState, index);
    }

    int LuaManager::get_int_from_state(int index)
    {
        return lua_tointeger(currentState, index);
    }

    void LuaManager::createNewState(bool openLibs)
    {
        log.log("Creating new lua state");
        close();
        currentState = luaL_newstate();
        if(openLibs)
        {
            luaL_openlibs(currentState);
        }
    }

    void LuaManager::registerMethod(string methodName, lua_CFunction func)
    {
        log.log("Registering lua method: " + methodName);
        lua_register(currentState, methodName.c_str(), func);
    }

    int LuaManager::loadFile(string filePath)
    {
        log.log("Loading lua file: " + filePath);
        return runWithErrCheck(luaL_loadfile(currentState, filePath.c_str()));
    }

    int LuaManager::executeState()
    {
        log.log("Executing current state");
        return runWithErrCheck(lua_pcall(currentState, 0, LUA_MULTRET, 0));
    }

    int LuaManager::callLuaMethod(string method)
    {
        log.log("Calling lua method: " + method);        
        return executeLuaString(method + "()");
    }

    int LuaManager::executeLuaString(string luaCode)
    {
        log.log("executing lua code snippet: " + luaCode);
        return runWithErrCheck(luaL_dostring(currentState, luaCode.c_str()));
    }


    void LuaManager::close()
    {
        log.log("Closing lua state");
        if (currentState != nullptr)
        {
            lua_close(currentState);
            currentState = nullptr;
        }
    }

}
