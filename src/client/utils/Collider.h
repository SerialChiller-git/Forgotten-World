#include <SFML/Graphics.hpp>

class Collider{
public:
    sf::FloatRect bounds;

    Collider() = delete;

    Collider (const sf::FloatRect& bounds);
    void draw(sf::RenderTarget& target);
};