#pragma once;
#include<Inventory.h>


Inventory::Inventory()
{
    isActive = false;
}


void Inventory::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    const int spriteSize = 32;
    const int columns = 5;
    if(isActive){
        for(int i = 0; i < inventory_size; i++){
            sf::RenderStates newStates = states;    
            int col = i % columns;
            int row = i / columns;
            newStates.transform.translate(sf::Vector2f(
                static_cast<float>(col * spriteSize),
                static_cast<float>(row * spriteSize)
            ));
            target.draw(sprite, newStates);
        }
    }
}