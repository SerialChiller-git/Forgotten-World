#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include "Player.h"

class Game
{
private:
    void processEvents();
    void update();
    void render();
    sf::RenderWindow mWindow;
    sf::Clock deltaClock;
    sf::Time deltaTime;
    Player player;
public:
    Game();
    ~Game() = default;
    void run();    
};


