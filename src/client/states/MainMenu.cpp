#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window, int& stateIndex):
    State(window),
    stateIndex(stateIndex)
{   
    background.setSize(sf::Vector2f(window->getSize()));
    background.setFillColor(sf::Color::Magenta);
}

MainMenu::~MainMenu()
{

}

void MainMenu::render(sf::RenderWindow* target){
    target->draw(background);
}

void MainMenu::update(sf::Time deltaTIme){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Num1)){
        changeState(stateIndex, 1);
    }
}
