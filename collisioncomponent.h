#ifndef COLLISION_COMPONENT_H
#define COLLISION_COMPONENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "component.h"

///Class
class CollisionComponent : public Component
{
protected:

public:

    CollisionComponent(){}
    CollisionComponent(unsigned int inID) : Component(inID){flag = 1<<COMPONENT_COLLISION;}

    //PositionComponent(){oldPosition = sf::Vector2f(); position = sf::Vector2f();}
    //PositionComponent(float x, float y){oldPosition = position; oldPositionRemainder = positionRemainder;
    //                                    position = sf::Vector2i(int(x), int(y)); positionRemainder = sf::Vector2f(x - position.x, y - position.y);}
    //PositionComponent(PositionComponent& positionComponent){oldPosition = positionComponent.oldPosition; oldPositionRemainder = positionComponent.oldPositionRemainder;
    //                                                        position = positionComponent.position; positionRemainder = positionComponent.positionRemainder;}

};

#endif


