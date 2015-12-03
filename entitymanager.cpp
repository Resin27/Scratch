#include <iostream>
#include "entitymanager.h"

EntityManager::EntityManager()
{
    entityCount = 0;
    entityMask.resize(MAX_ENTITY_COUNT);

    positionRegister.resize(MAX_ENTITY_COUNT);
    velocityRegister.resize(MAX_ENTITY_COUNT);

}

unsigned int EntityManager::addEntity()
{
    if(entityCount < MAX_ENTITY_COUNT)
    {
        if(deadEntities.size() > 0)
        {
            unsigned int newEntity = deadEntities.back();
            deadEntities.pop_back();
            aliveEntities.push_back(newEntity);
            ++entityCount;
            return newEntity;
        }
        else
        {
            aliveEntities.push_back(entityCount);
            return entityCount++;
        }
    }

    return -1;

    /*if(entityCount < MAX_ENTITY_COUNT)
        ++entityCount;
    return entityCount;*/
    //return entityCount++ < MAX_ENTITY_COUNT;
    //return -1;
}
