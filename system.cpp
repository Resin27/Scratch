#include "system.h"
#include <iostream>

/*void System::registerEntities()
{
    registeredEntities.clear();

    for(auto &entityID : eManager->entityMask)
    {
        if(checkMask(entityID))
        {
            registeredEntities.push_back(entityID);
        }
    }
}*/

bool System::registerEntity(int entityID)
{
    if(isRegistered(entityID))
    {
        return false;
    }
    if(checkMask(entityID))
    {
        registeredEntities.push_back(entityID);
        return true;
    }
    return false;
}

bool System::deregisterEntity(int entityID)
{
    for(auto it = registeredEntities.begin(); it != registeredEntities.end(); ++it)
    {
        if((*it) == entityID)
        {
            registeredEntities.erase(it);
            return true;
        }
    }
    return false;
}

bool System::isRegistered(int entityID)
{
    for(auto &registeredEntity : registeredEntities)
    {
        if(registeredEntity == entityID)
        {
            return true;
        }
    }
    return false;
}

void System::processApplicants()
{
    for(auto &applicant : applicants)
    {
        if(checkMask(eManager->entityMask[applicant]) && isRegistered(applicant))
        {
            if(isRegistered(applicant))
            {
                registerEntity(applicant);
            }
        }
        else
        {
            if(isRegistered(applicant))
            {
                deregisterEntity(applicant);
            }
        }
    }
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

