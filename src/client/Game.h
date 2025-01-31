#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include "Player.h"
#include<lua.hpp>
#include <LuaBridge/LuaBridge.h>
#include <iostream>

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
public:
    Game();
    ~Game() = default;
    void initialize();
    void run();    
};


