#include "GameState.h"


GameState::GameState(sf::RenderWindow* window, int& stateIndex):
    State(window),
    stateIndex(stateIndex)
{   
    player.setPosition({10,10});player.load("assets/player.png", {64,64});
}

GameState::~GameState()
{
}

void GameState::render(sf::RenderWindow* target){
    target->draw(player);
}

void GameState::update(sf::Time deltaTIme){
    player.update(deltaTIme);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape)){
        changeState(stateIndex, 0);
    }
}
