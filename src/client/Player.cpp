#include "Player.h"

Player::Player(){
    this->setOrigin({32.0f, 32.0f}); // because sprite is 64x64 so did this to center it
    playerView.setSize({600, 800});
    playerView.setCenter(this->getPosition()); 
}


void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    if(alive){
        target.draw(sprite, states);
    }
}

void Player::setTextureIndex(int x, int y){
    sprite.setTextureRect(sf::IntRect({(x)*64, (y)*64}, {64 , 64}));
}

void Player::update(sf::Time deltaTime){
    playerView.setCenter(this->getPosition());
    sf::Vector2f movement = {0,0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        this->setTextureIndex(3,0);
        movement.x -= 1;                    
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        this->setTextureIndex(2,0);
        movement.x += 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        this->setTextureIndex(0,0);
        movement.y -= 1;                
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        this->setTextureIndex(1,0);
        movement.y += 1;                
    }
    movement = normalize(movement);
    movement.x*= this->speed*deltaTime.asSeconds();
    movement.y*= this->speed*deltaTime.asSeconds();
    this->move(movement);

}
