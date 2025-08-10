#pragma once
#include <Collider.h>

Collider::Collider (const sf::FloatRect& bounds) : bounds(bounds) {
        
}

void Collider::draw(sf::RenderTarget& target){
        sf::RectangleShape rect;
        rect.setPosition(sf::Vector2f({bounds.position.x, bounds.position.y}));
        rect.setSize(sf::Vector2f({bounds.size.x, bounds.size.y}));
        rect.setFillColor(sf::Color({1, 0, 0, 1}));  // fully transparent
        rect.setOutlineColor(sf::Color::Red);
        rect.setOutlineThickness(1.f);
        target.draw(rect);
}