#include "GameState.h"


GameState::GameState(sf::RenderWindow* window):
    State(window)
{
}

GameState::~GameState()
{
}

void GameState::render(sf::RenderTarget* target){

}

void GameState::update(sf::Time deltaTIme){
    std::cout << "Hello from GameState \n";
}

void GameState::endState(){
    
}