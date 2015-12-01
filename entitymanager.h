#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>

#include "component.h"
#include "componenttypes.h"
#include "positioncomponent.h"
#include "velocitycomponent.h"

static const unsigned int MAX_ENTITY_COUNT = 65535;

template <class T>
class ComponentTable
{
protected:
    int index[MAX_ENTITY_COUNT] = {-1};
    std::vector<T> componentRegister;
    typename std::vector<T>::iterator first = componentRegister.begin();
    typename std::vector<T>::iterator last = componentRegister.end();
public:
    T& getComponent(unsigned int entityID){if(index[entityID] >= 0) return componentRegister[index[entityID]]; else return nullptr;}
    void addComponent(unsigned int entityID, T component){index[entityID] = componentRegister.size(); componentRegister.push_back(component);}
    void removeComponent(unsigned int entityID){if(index[entityID] >= 0) {componentRegister.erase(first+index[entityID]);}}
};

///Class
class EntityManager
{
protected:

public:

    unsigned int entityCount;
    //int entityMask[MAX_ENTITY_COUNT];
    std::vector<unsigned int> aliveEntities;
    std::vector<unsigned int> deadEntities;
    std::vector<int> entityMask;
    //bool worldChanged;

    //std::map<std::string, int> prototype;
    //ComponentTable<PositionComponent> positionRegister2;
    //ComponentTable<VelocityComponent> velocityRegister2;
    std::vector<PositionComponent> positionRegister;
    std::vector<VelocityComponent> velocityRegister;

    //PositionComponent positionComponent[MAX_ENTITY_COUNT];
    //VelocityComponent velocityComponent[MAX_ENTITY_COUNT];
    //HitboxComponent hitboxComponent[MAX_ENTITY_COUNT];
    //SpriteComponent spriteComponent[MAX_ENTITY_COUNT];
    //InputComponent inputComponent[MAX_ENTITY_COUNT];
    //PlayerComponent playerComponent[MAX_ENTITY_COUNT];


    EntityManager();

    unsigned int addEntity();/*
    void addEntity(const std::string& entityType); ///Here, int will be the "entityType." Which will be determined from the streamed world info.
    void removeEntity(int ID);
    void removeAllEntities();
    void addComponent(int ID, ComponentType componentType);
    void removeComponent(int ID, ComponentType componentType);

    void printEntities();*/
    //void createEntity(World& world, std::string entityType);

};

#endif

