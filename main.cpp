
#include <iostream>
#include "gameengine.h"
#include "teststate.h"

#include "scriptengine.h"

int main()
{
    GameEngine game;
    //ScriptEngine lua;

    game.init();
    game.pushState(new TestState);

    game.run();
    game.cleanUp();

    return 0;
}
