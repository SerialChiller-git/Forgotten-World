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

sf::Vector2f Entity::normalize(sf::Vector2f& source){
    float length = std::sqrt(source.x * source.x + source.y * source.y);
    if(length != 0) {
        return sf::Vector2f(source.x/length, source.y/length);
    }
    return source;
}