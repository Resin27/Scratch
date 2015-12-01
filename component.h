#ifndef COMPONENT_H
#define COMPONENT_H

#include "componenttypes.h"

///Class
class Component
{
protected:

    unsigned int entityID;
    unsigned int flag;

public:

    Component(){}
    Component(unsigned int ID) : entityID(ID){}
    virtual ~Component(){}

    virtual void setID(unsigned int ID){entityID = ID;}
    virtual unsigned int getID(){return entityID;}
    virtual unsigned int getFlag(){return flag;}

};

#endif
