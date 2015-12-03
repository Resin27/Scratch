#include "teststate.h"

void TestState::init(GameEngine *game)
{

    //this->game = game;
    assetManager = &(game->assetManager);
    entityManager = &(game->entityManager);

    mover.setEntityManager(entityManager);
    /*for(unsigned int i = 0; i < MAX_ENTITY_COUNT+20; i++)
        if(entityManager->addEntity())
            std::cout << entityManager->entityCount << " entities!" << std::endl;
        else
            std::cout << "Too many entities!" << std::endl;*/

    std::cout << (int)entityManager->entityMask.capacity() << std::endl;
    std::cout << (int)entityManager->positionRegister.capacity() << std::endl;
    std::cout << (int)entityManager->velocityRegister.capacity() << std::endl;

    std::cout << "New EntityID: " << entityManager->addEntity() << std::endl;
    entityManager->entityMask[0] += 1<<COMPONENT_POSITION|1<<COMPONENT_VELOCITY;
    entityManager->positionRegister[0].setID(0);
    entityManager->positionRegister[0].position = sf::Vector2i(20,30);
    entityManager->velocityRegister[0].setID(0);
    entityManager->velocityRegister[0].velocity = sf::Vector2f(5.4,12.9);


    //mover.registerEntities();
    std::cout<<"EntityMask:0: " << entityManager->entityMask[0] << std::endl;
    std::cout<<"SystemMask:   " << mover.getMask() << std::endl;
    std::cout<<"MasksCheckOut:" << mover.checkMask(0) << std::endl;
    std::cout<<"EntityRegged: " << mover.registerEntity(0) <<std::endl;


}

void TestState::cleanUp()
{

}

void TestState::pause()
{

}

void TestState::resume()
{

}

void TestState::handleEvents()
{

}

void TestState::update(float dt)
{
    mover.update(dt);
    //std::cout << "MANAGE: Entity[" << 0 << "]: " << entityManager->positionRegister[0].position.x << "," << entityManager->positionRegister[0].position.y <<std::endl;
}

void TestState::draw()
{
    //game->window.clear();
    //game->window.draw(*firstObject.getSprite());
    //for(int i = 0; i < 4; i++)
        //for(int j = 0; j < 4; j++)
            //game->window.draw(*objectArray[i][j]->getSprite());
    //game->window.display();
}

