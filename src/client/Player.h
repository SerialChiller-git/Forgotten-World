#pragma once
#include<SFML/Graphics.hpp>
#include "Entity.h"

class Player:public Entity
{
private:
    bool alive = true;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void setTextureIndex(int x, int y);
public:
    
};
