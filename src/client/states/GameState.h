#pragma once
#include "State.h"

class GameState : public State
{
private:
    virtual void update(sf::Time deltaTIme);
    virtual void render(sf::RenderWindow* target = nullptr);
    virtual void gui();
    
public:
    GameState(sf::RenderWindow* window, int& stateIndex);
    ~GameState();
    Player player;
    int& stateIndex;
};
