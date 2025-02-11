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

void State::updateMousePositions(){
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(mousePosWindow);
}
