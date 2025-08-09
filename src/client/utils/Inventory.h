#include<Entity.h>

class Inventory : public Entity
{
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
public:
    Inventory();
    int inventory_size = 10;
    bool isActive;
};


