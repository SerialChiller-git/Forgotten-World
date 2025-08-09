#include "GameState.h"


GameState::GameState(sf::RenderWindow* window, int& stateIndex):
    State(window),
    stateIndex(stateIndex)
{   
    player.setPosition({10,10});player.load("assets/player.png", {64,64});
    inventory.load("assets/inventory_slot.png", {32,32});
}

GameState::~GameState()
{
}

void GameState::render(sf::RenderWindow* target){
    target->setView(player.playerView);
    target->draw(player);
    target->draw(inventory);
}

void GameState::update(sf::Time deltaTIme){
    this->updateMousePositions();
    player.update(deltaTIme);

    inventory.setPosition( player.getPosition() + sf::Vector2f(50.f, 50.f));
    
}

void GameState::gui(){
    
}

void GameState::processEvents(const sf::Event event){
    if (const auto keyPressed = event.getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                changeState(stateIndex, 0);
            }
            else if(keyPressed->scancode == sf::Keyboard::Scancode::I){
                inventory.isActive = !inventory.isActive;
            }  
        }
}
