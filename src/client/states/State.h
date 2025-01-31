#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include "Player.h"
#include<lua.hpp>
#include <LuaBridge/LuaBridge.h>
#include<ctime>
#include<fstream>
#include<vector>
#include<stack>
#include<map>

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>



class State
{
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
public:
    State(sf::RenderWindow* window);
    virtual ~State();
    virtual void update(sf::Time deltaTIme) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
    virtual void endState() = 0;
};
