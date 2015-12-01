#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

//#include "inputmanager.h"
#include "assetmanager.h"
#include "entitymanager.h"

class GameState;

///Class
class GameEngine
{
protected:

    sf::Clock timer;
    const sf::Time dt = sf::seconds(1.f/60.f);
    sf::Time currentTime;
    sf::Time accumulator;

    std::vector<GameState*> states;
    bool running;

public:

    sf::RenderWindow window;
    //InputManager inputManager;
    AssetManager assetManager;
    EntityManager entityManager;

    void init();
    void run();
    void cleanUp();

    void changeState(GameState *state);
    void pushState(GameState *state);
    void popState();

    void handleEvents();
    void update();
    void draw();

    bool isRunning(){return running;}
    void quit(){running = false;}
};

#endif

