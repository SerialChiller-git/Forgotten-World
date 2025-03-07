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
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    if (luaL_dofile(L, "config/config.lua") != LUA_OK) {
        std::cerr << "Error loading Lua config: " << lua_tostring(L, -1) << std::endl;
        return;
    }

    try {
        luabridge::LuaRef config = luabridge::getGlobal(L, "config");
        if (config.isTable()) {
            int windowX = config["window"]["width"].cast<int>();
            int windowY = config["window"]["height"].cast<int>();
            sf::Vector2u mWindow_bounds(windowX, windowY);
            mWindow.setSize(mWindow_bounds);
            std::cout << "Window size set to: " << windowX << "x" << windowY << std::endl;
        } else {
            std::cerr << "Error: 'config' is not a table" << std::endl;
        }
    } catch (const luabridge::LuaException& e) {
        std::cerr << "LuaException: " << e.what() << std::endl;
    }
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