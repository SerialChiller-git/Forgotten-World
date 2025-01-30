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

void Player::update(sf::Time deltaTime){
    sf::Vector2f movement = {0,0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        movement.x -= 1;                    
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        movement.x += 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        movement.y -= 1;                
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        movement.y += 1;                
    }
    movement = normalize(movement);
    movement.x*= this->speed*deltaTime.asSeconds();
    movement.y*= this->speed*deltaTime.asSeconds();
    this->move(movement);
}

void Player::drawInvetory(sf::RenderWindow& window) const{
    const auto& items = inventory.getItems();
    float x = 10.0f;
    float y = 10.0f;
    for (const auto& item : items) {
        std::cout << "inventory";
        sf::Text text(inventory.font , "");
        text.setString(item.getName());
        text.setPosition({x, y + sprite.getGlobalBounds().size.y + 5});
        text.setCharacterSize(12);
        text.setFillColor(sf::Color::White);
        window.draw(text);

        y += sprite.getGlobalBounds().size.y + 30;
    }
}