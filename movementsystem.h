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

    std::vector<PositionComponent*> positionRegister;
    std::vector<VelocityComponent*> velocityRegister;

    const std::vector<std::type_index> types{typeid(PositionComponent), typeid(VelocityComponent)};

public:

    MovementSystem() : System(1<<COMPONENT_POSITION | 1<<COMPONENT_VELOCITY){setComponentRegisters(types);}

    void registerEntities();
    bool registerEntity(unsigned int entityID);
    bool deregisterEntity(unsigned int entityID);

    bool isRegistered(unsigned int entityID);

    void processApplicants();

    void update(float dt);
};

#endif

