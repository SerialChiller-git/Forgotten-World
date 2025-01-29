#include "Entity.h"

Entity::Entity(): texture(), sprite(texture){}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(vertices, states);
}

bool Entity::load(const std::filesystem::path& texture, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height){
    if (!this->texture.loadFromFile(texture)){
            return false;
    }
        // resize the vertex array to fit the level size
    vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    vertices.resize(width * height * 6);
    return true;
}

bool Entity::load(const std::filesystem::path& texture, sf::Vector2u tileSize){
    if(!this->texture.loadFromFile(texture)){
        return false;
    }

    this->sprite.setTexture(this->texture);
    sprite.setTextureRect(sf::IntRect({0, 0}, {64, 64}));
    return true;

}