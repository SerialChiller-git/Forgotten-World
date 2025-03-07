#pragma once
#include "State.h"

class MainMenu : public State
{
private:
    virtual void update(sf::Time deltaTIme);
    virtual void render(sf::RenderWindow* target = nullptr);
    virtual void gui();
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    void initBackground();
public:
    MainMenu(sf::RenderWindow* window, int& stateIndex);
    virtual ~MainMenu();
    int& stateIndex;
};
