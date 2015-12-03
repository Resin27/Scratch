#ifndef SYSTEM_H
#define SYSTEM_H

#include "entitymanager.h"

///Class
class System
{
protected:

    unsigned int subscriptionMask = 0;

    std::vector<int> registeredEntities;
    std::vector<int> applicants;

    EntityManager* eManager;

public:

    System(){}
    System(unsigned int inMask) : subscriptionMask(inMask){}
    virtual ~System(){}

    virtual unsigned int getMask(){return subscriptionMask;}
    virtual bool checkMask(int entityID){return (eManager->entityMask[entityID] & subscriptionMask) == subscriptionMask;}
    virtual void setEntityManager(EntityManager* entityManager){eManager = entityManager;}

    //virtual void registerEntities();
    virtual bool registerEntity(int entityID);
    virtual bool deregisterEntity(int entityID);
    virtual bool isRegistered(int entityID);

    virtual void processApplicants();
};

#endif


