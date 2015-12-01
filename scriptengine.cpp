#include "scriptengine.h"

ScriptEngine::ScriptEngine()
{
    L = luaL_newstate();
    luaL_openlibs(L);

    luaL_loadfile(L, "scripts/get_keys.lua");
    luaL_dofile(L, "scripts/get_keys.lua");

    LuaRef get_keys = getGlobal(L, "get_keys");
    script["get_keys"] = &get_keys;

    LuaRef testvalue = getGlobal(L, "testvalue");
    std::cout<< "Value is: " << testvalue.cast<int>() << std::endl;
    testvalue = 6;
        std::cout<< "Value is: " << testvalue << std::endl;


    LuaRef tablet(L);
    tablet = newTable(L);

    tablet["key1"] = "whatever";
    tablet["key2"] = "yep!";

    LuaRef keys(L);
    keys = (*script["get_keys"])(5);
    if(!keys.isNil())
        std::cout << keys[1].cast<std::string>() << std::endl;

    lua_close(L);
}
