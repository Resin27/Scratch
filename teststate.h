#ifndef TEST_STATE_H
#define TEST_STATE_H

#include "gamestate.h"

//#include "gameobject.h"
#include "movementsystem.h"


class TestState : public GameState
{
protected:

    //GameObject firstObject;
    //GameObject *objectArray[4][4];
    //World world;
    //EntityManager eManager;
    //ControlManager cManager;

    MovementSystem mover;// = MovementSystem(1<<COMPONENT_POSITION | 1<<COMPONENT_VELOCITY);

public:

    void init(GameEngine *game);
    void cleanUp();

    void pause();
    void resume();

    void handleEvents();
    void update(float dt);
    void draw();
};

#endif

