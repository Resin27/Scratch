#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "system.h"
//#include "entitymanager.h"
#include "componenttypes.h"
#include "positioncomponent.h"
#include "velocitycomponent.h"

///Class
class MovementSystem : public System
{
protected:

public:

    MovementSystem() : System(1<<COMPONENT_POSITION | 1<<COMPONENT_VELOCITY){}

    void update(float dt);
};

#endif

