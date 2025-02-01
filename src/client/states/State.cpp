#include "State.h"

State::State(sf::RenderWindow* window)
{
    this->window = window; 
}

State::~State()
{
}

void State::update(sf::Time deltaTIme){

}
void State::render(sf::RenderWindow* target){

}

void State::changeState(int& stateIndex, int nextIndex){
    stateIndex = nextIndex;
}
