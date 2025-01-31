#pragma once
#include "GameState.h"
class Game
{
private:
    void processEvents();
    void update();
    void render();
    void loadConfig();
    sf::RenderWindow mWindow;
    sf::Clock deltaClock;
    sf::Time deltaTime;
    Player player;
    std::stack<State*> states;

    void initState();
public:
    Game();
    ~Game();
    void initialize();
    void run();    
};


