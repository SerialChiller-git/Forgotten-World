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
#include <imgui.h>
#include <imgui-SFML.h>



class State
{
private:
    std::vector<sf::Texture> textures;
public:
    State(sf::RenderWindow* window);
    virtual ~State();
    virtual void update(sf::Time deltaTIme) = 0;
    virtual void render(sf::RenderWindow* target = nullptr) = 0;
    virtual void gui() = 0;
    
protected:
    void changeState(int& stateIndex, int nextIndex);
    sf::RenderWindow* window;
};
