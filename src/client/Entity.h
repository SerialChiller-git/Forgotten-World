#pragma once
#include<SFML/Graphics.hpp>
#include<filesystem>

class Entity : public sf::Drawable, public sf::Transformable
{
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    Entity();
    virtual ~Entity() = default;
    virtual void update(float deltaTime){};
    virtual bool load(const std::filesystem::path& texture, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height); // Load for multi-tile obj
    virtual bool load(const std::filesystem::path& texture, sf::Vector2u tileSize); // load for single-tile obj
    sf::Sprite sprite;
    sf::Texture texture;
    sf::VertexArray vertices;
};

