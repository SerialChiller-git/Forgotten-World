#include "Game.h"

Game::Game():
    mWindow(sf::VideoMode({800, 600}), "Forgotten World")
{
    player.setPosition({10,10});
}

void Game::run(){
    player.load("assets/player.png", {64,64});
    while (mWindow.isOpen()){    
        processEvents();  // Process events  
        render();           // Render the game
    }
}

void Game::processEvents(){
     while (const std::optional event = mWindow.pollEvent()){
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>()){
                mWindow.close();
            }
        }
}

void Game::render(){
    mWindow.clear();
    mWindow.draw(player);
    mWindow.display();
}