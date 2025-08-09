#include "Game.h"

Game::Game():
    mWindow(sf::VideoMode({800, 600}), "Forgotten World")
{   

    loadConfig();
    this->initState();    
    
}

Game::~Game(){
    while(!this->states.empty()){
        delete this->states.back();
        this->states.pop_back();
    }
}

void Game::loadConfig(){
    mWindow.setSize(sf::Vector2u(800, 800));
    return;
}

void Game::run(){
    ImGui::SFML::Init(mWindow);

    while (mWindow.isOpen()){    
        deltaTime = deltaClock.restart();
        processEvents();  // Process events  
        update();         // Update the game 
        render();         // Render the game
    }

    ImGui::SFML::Shutdown();
}

void Game::processEvents(){
     while (const std::optional event = mWindow.pollEvent()){
        // "close requested" event: we close the window
        ImGui::SFML::ProcessEvent(mWindow, *event);

        if(!this->states.empty()){
            this->states[stateIndex] -> processEvents(*event);
        }

        if (event->is<sf::Event::Closed>()){
            mWindow.close();
        }
    }
    
}

void Game::update(){
    ImGui::SFML::Update(mWindow, deltaClock.restart());
    if(!this->states.empty()){
        this->states[stateIndex]->update(deltaTime); //Update a specific state
    }
}

void Game::render(){
    mWindow.clear();
    if(!this->states.empty()){
        this->states[stateIndex]->render(&this->mWindow); //Render a specific state
    }
    if(!this->states.empty()){
        this->states[stateIndex]->gui();
    }
    ImGui::SFML::Render(mWindow);
    mWindow.display();
}

void Game::initState(){
    this->states.push_back(new MainMenu(&this->mWindow, stateIndex));
    this->states.push_back(new GameState(&this->mWindow, stateIndex)); 
}