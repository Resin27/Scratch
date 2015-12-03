#include "movementsystem.h"
#include <iostream>

void MovementSystem::update(float dt)
{
    std::vector<PositionComponent>& positionRegister = eManager->positionRegister;
    std::vector<VelocityComponent>& velocityRegister = eManager->velocityRegister;
    for(auto &registeredEntity : registeredEntities)
    {
        PositionComponent& pos = positionRegister[registeredEntity];
        VelocityComponent& vel = velocityRegister[registeredEntity];
        sf::Vector2f delta = vel.velocity * dt;
        delta = delta + pos.remainder;

        pos.oldPosition = pos.position;
        pos.oldRemainder = pos.remainder;

        pos.position = pos.position + sf::Vector2i(delta);
        pos.remainder.x = (delta.x - sf::Vector2i(delta).x);
        pos.remainder.y = (delta.y - sf::Vector2i(delta).y);
        //std::cout << "SYSTEM: Entity[" << registeredEntity << "]: " << positionRegister[registeredEntity].position.x << "," << positionRegister[registeredEntity].position.y <<std::endl;
    }
}

/*void MovementSystem::registerEntities()
{
    positionRegister.clear();
    velocityRegister.clear();
    entityCount = 0;

    for(unsigned int i = 0; i < eManager->entityCount; i++)
    {
        if(checkMask(eManager->entityMask[i]))
        {
            positionRegister.push_back(&eManager->positionRegister[i]);
            velocityRegister.push_back(&eManager->velocityRegister[i]);
            ++entityCount;
        }
    }
}

bool MovementSystem::registerEntity(int entityID)
{
    if(isRegistered(entityID))
    {
        return false;
    }
    if(checkMask(eManager->entityMask[entityID]))
    {
        positionRegister.push_back(&eManager->positionRegister[entityID]);
        velocityRegister.push_back(&eManager->velocityRegister[entityID]);
        ++entityCount;
        return true;
    }
    return false;
}

bool MovementSystem::deregisterEntity(int entityID)
{
    for(unsigned int i = 0; i < entityCount; i++)
    {
        if((positionRegister[i]->getID() == velocityRegister[i]->getID()) == entityID)
        {
            positionRegister[i] = positionRegister[entityCount-1];
            velocityRegister[i] = velocityRegister[entityCount-1];
            --entityCount;
            return true;
        }
    }
    return false;
}

bool MovementSystem::isRegistered(int entityID)
{
    for(unsigned int i = 0; i < entityCount; i++)
    {
        if((positionRegister[i]->getID() == velocityRegister[i]->getID()) == entityID)
        {
            return true;
        }
    }
    return false;
}

void MovementSystem::processApplicants()
{
    for(unsigned int i = 0; i < applicants.size(); i++)
    {
        if(checkMask(eManager->entityMask[i]))
        {
            if(!isRegistered(i))
            {
                registerEntity(i);
            }
        }
        else
        {
            if(isRegistered(i))
            {
                deregisterEntity(i);
            }
        }
    }
}*/
