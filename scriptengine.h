#ifndef SCRIPT_ENGINE_H
#define SCRIPT_ENGINE_H
/*
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>*/
#include <iostream>
#include <map>
#include <vector>

#include <LuaBridge.h>
extern "C"
{
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
}

using namespace luabridge;

///Class
class ScriptEngine
{
private:

    lua_State* L;

    std::map<std::string, LuaRef*> script;

public:

    ScriptEngine();

    //bool loadScript(std::string scriptFile)
};

#endif

