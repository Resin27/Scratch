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
    entityManager->velocityRegister[0].setID(0);

    mover.registerEntities();

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
    //mover.update(dt);
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

