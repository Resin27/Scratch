#ifndef SYSTEM_H
#define SYSTEM_H

#include "entitymanager.h"
#include <typeinfo>
#include <typeindex>
///Class
class System
{
protected:

    std::vector<std::vector<Component*>> registers;

    EntityManager* eManager;

    unsigned int entityCount;
    unsigned int subscriptionMask;

    std::vector<unsigned int> applicants;

public:

    System() : entityCount(0){}
    System(unsigned int inMask) : entityCount(0), subscriptionMask(inMask){}
    virtual ~System(){}

    virtual void setEntityManager(EntityManager* entityManager){eManager = entityManager;}
    virtual void setComponentRegisters(const std::vector<std::type_index>& types)
    {
        for(unsigned int i = 0; i < types.size(); i++)
        {
            registers.push_back(std::vector<Component*>());
        }
       // std::cout << "Number of component types registered: " << registers.size() << std::endl;
        //PositionComponent* pos = new PositionComponent;
        //registers[0].push_back(pos);
    }

    virtual unsigned int getCount(){return entityCount;}

    virtual unsigned int getMask(){return subscriptionMask;}
    virtual bool checkMask(unsigned int entityMask){return (entityMask & subscriptionMask) == subscriptionMask;}

    virtual void processApplicants() = 0;

};

#endif


