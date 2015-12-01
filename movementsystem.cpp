#include "movementsystem.h"
#include <iostream>

void MovementSystem::update(float dt)
{
    for(unsigned int i = 0; i < entityCount; i++)
    {
        sf::Vector2f delta = velocityRegister[i]->velocity * dt;
        delta = delta + positionRegister[i]->remainder;

        positionRegister[i]->oldPosition = positionRegister[i]->position;
        positionRegister[i]->oldRemainder = positionRegister[i]->remainder;

        positionRegister[i]->position = positionRegister[i]->position + sf::Vector2i(delta);
        positionRegister[i]->remainder.x = (delta.x - sf::Vector2i(delta).x);
        positionRegister[i]->remainder.y = (delta.y - sf::Vector2i(delta).y);
    }
}

void MovementSystem::registerEntities()
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

bool MovementSystem::registerEntity(unsigned int entityID)
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

bool MovementSystem::deregisterEntity(unsigned int entityID)
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

bool MovementSystem::isRegistered(unsigned int entityID)
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
}
