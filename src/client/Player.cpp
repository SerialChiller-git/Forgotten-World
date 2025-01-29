#include "Player.h"

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    if(alive){
        target.draw(sprite, states);
    }
}

void Player::setTextureIndex(int x, int y){
    sprite.setTextureRect(sf::IntRect({x*64, y*64}, {(x+1)*64 , (y+1)*64}));
}