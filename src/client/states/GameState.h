#pragma once
#include "State.h"

class GameState : public State
{
private:
    virtual void update(sf::Time deltaTIme);
    virtual void render(sf::RenderTarget* target = nullptr);
    void endState();
public:
    GameState(sf::RenderWindow* window);
    ~GameState();
};
