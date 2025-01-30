#pragma once
#include<string>
#include<SFML/Graphics.hpp>

class Item{
public:
    Item(const std::string& name , int id, const sf::Texture& texture):
        name(name), id(id), sprite(texture){}
    std::string getName() const { return name; }
    int getId() const { return id; }
    const sf::Sprite& getSprite() const { return sprite; }
    int id;
private:
    std::string name;
    sf::Sprite sprite;
};