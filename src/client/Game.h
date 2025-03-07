#pragma once
#include "GameState.h"
#include "MainMenu.h"
#include <cstdlib>
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
    int stateIndex = 0;
    void initState();
public:
    Game();
    ~Game();
    void initialize();
    void run(); 
    std::vector<State*> states;
    
};


