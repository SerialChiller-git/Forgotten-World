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
public:
    Game();
    ~Game() = default;
    void run();
private:
    sf::RenderWindow mWindow;
    Player player;

};


