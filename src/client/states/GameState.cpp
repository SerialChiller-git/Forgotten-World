#include "GameState.h"


GameState::GameState(sf::RenderWindow* window, int& stateIndex):
    State(window),
    stateIndex(stateIndex)
{   
    player.setPosition({50,50});player.load("assets/player.png", {64,64});
    inventory.load("assets/inventory_slot.png", {32,32});

    const int level[] = {
    17,19,18,17,17,19,16,16,16,18,16,16,16,19,18,18,16,17,18,16,17,16,17,16,17,16,16,19,18,19,19,18,17,18,18,19,19,18,19,19,
19,19,17,19,17,16,16,17,17,19,17,17,19,19,18,18,18,18,17,19,18,19,18,17,17,16,16,16,16,16,19,19,18,17,17,19,16,17,18,16,
18,19,18,18,18,19,16,17,18,16,18,19,19,19,17,16,19,18,18,17,17,18,17,19,17,16,19,17,17,18,16,19,17,18,17,17,16,17,16,18,
19,16,16,19,17,18,18,17,17,17,16,17,17,19,18,16,18,17,16,16,17,17,17,19,19,17,17,19,16,18,18,16,18,18,18,16,18,19,16,16,
17,17,17,16,17,19,18,17,18,17,18,17,18,16,16,19,17,18,19,18,17,16,18,16,18,18,17,17,17,16,17,18,19,18,17,18,17,17,19,16,
17,19,16,16,17,19,18,18,17,19,17,17,17,19,18,16,18,19,16,17,18,18,19,17,18,18,19,18,19,18,18,19,17,19,18,16,18,17,19,19,
17,19,18,18,17,19,16,18,19,18,19,19,16,18,17,19,16,16,19,19,17,18,16,19,17,18,17,16,17,16,16,17,16,17,17,19,18,18,16,17,
19,19,19,19,19,19,17,19,17,19,18,19,17,19,16,16,18,19,19,18,17,18,18,19,18,19,17,16,18,16,16,16,18,19,16,17,19,16,16,19,
17,16,19,16,18,17,19,17,19,16,16,19,17,16,19,17,19,19,19,16,17,17,17,16,16,19,19,16,17,19,18,19,17,17,18,16,17,18,16,19,
17,16,17,19,17,17,18,18,18,16,18,19,19,17,19,16,16,17,19,18,18,19,16,19,17,19,19,17,16,16,16,18,18,18,17,17,18,16,18,19,
19,17,17,17,16,19,19,19,19,16,19,16,19,17,19,16,16,18,18,18,16,19,18,19,19,18,18,16,17,18,17,17,18,18,18,18,17,19,18,17,
16,17,17,18,16,18,19,16,19,16,19,19,18,17,19,16,19,19,19,17,17,17,16,19,18,19,18,18,19,16,18,18,17,17,17,18,16,16,17,19,
16,17,19,16,18,17,18,17,17,17,19,16,16,18,17,19,18,19,17,17,18,18,19,17,18,17,16,19,18,19,18,18,16,17,19,19,17,16,16,16,
17,18,19,19,18,19,18,17,17,19,19,17,18,18,19,6,17,18,19,19,16,17,17,18,19,19,18,16,19,17,18,17,19,16,16,16,16,18,16,18,
17,18,18,18,19,19,19,16,17,19,17,16,18,18,16,19,6,17,19,19,17,17,16,18,19,16,18,19,16,18,19,19,17,18,16,19,17,16,17,16,
18,18,18,18,19,18,19,19,18,18,17,19,18,17,7,9,10,6,16,18,16,18,17,6,6,6,17,16,18,18,16,19,19,17,18,19,17,17,18,16,
18,17,19,17,19,19,19,18,16,16,19,18,6,6,11,12,8,9,9,9,9,9,9,9,10,6,6,6,6,6,6,16,18,19,17,19,17,19,17,19,
17,19,18,16,16,19,19,18,19,19,7,9,9,9,15,12,12,12,12,12,12,12,12,12,8,9,9,9,9,9,10,6,18,17,18,18,16,18,17,19,
16,18,19,16,17,17,19,17,19,17,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,1,6,6,17,19,17,17,17,16,18,
18,19,17,18,19,18,16,17,16,18,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,1,6,6,6,6,18,16,17,19,18,
19,17,16,18,17,16,17,16,16,18,2,3,3,3,3,3,0,12,12,12,12,12,12,12,12,12,12,12,12,12,8,9,10,6,6,18,17,16,16,19,
19,18,19,16,19,19,19,17,16,16,16,6,17,6,18,6,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,8,9,10,6,17,17,19,19,
16,17,18,16,19,19,17,17,16,17,18,19,19,19,16,6,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,1,6,19,18,17,18,
19,17,19,18,16,18,17,16,17,18,16,18,17,18,17,17,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,1,18,17,16,19,18,
16,17,16,19,18,16,17,17,17,18,16,17,17,16,16,16,2,3,3,3,0,12,12,12,12,12,12,12,12,12,12,12,12,12,1,19,17,17,18,19,
18,16,18,16,19,17,18,17,17,16,19,17,16,16,17,17,6,6,6,6,11,12,12,12,12,12,12,12,12,12,12,13,3,3,5,16,16,18,17,19,
19,17,18,16,18,18,17,19,17,16,17,17,16,18,19,19,16,18,6,6,11,12,12,12,12,12,12,12,12,12,12,1,17,6,6,19,19,19,19,19,
18,19,19,17,16,19,16,17,17,16,19,18,18,17,16,17,16,19,6,6,11,12,12,12,12,12,12,12,12,12,12,1,17,17,6,18,19,18,16,17,
17,17,19,16,17,19,19,19,16,18,16,19,18,17,19,16,17,16,16,6,11,12,12,12,12,12,12,12,13,3,3,5,16,6,6,18,17,16,18,17,
19,18,18,18,17,18,17,17,17,18,19,17,19,19,18,17,17,19,16,16,2,3,3,3,3,3,3,3,5,16,6,6,6,6,18,19,19,18,19,18,
17,17,18,16,17,17,19,17,16,16,19,19,16,16,18,16,17,16,17,17,19,6,6,6,6,6,6,6,6,6,6,17,6,6,18,18,18,19,19,19,
17,16,17,17,18,18,17,19,18,19,17,18,18,17,17,18,19,17,19,17,18,18,18,16,6,6,16,19,19,17,17,19,19,16,17,19,18,18,18,18,
16,19,17,19,17,18,18,19,18,16,17,17,19,16,19,18,17,18,18,18,19,16,18,18,19,18,18,16,18,16,19,19,17,16,16,17,17,19,16,16,
19,16,16,16,17,18,17,17,19,19,19,16,17,18,16,17,19,18,17,18,18,16,17,16,19,16,19,17,19,18,19,17,17,16,18,16,17,18,16,18,
17,17,16,19,16,16,18,19,18,18,19,18,18,17,16,17,19,16,16,19,17,16,18,18,17,18,19,17,17,17,19,19,18,16,17,18,16,17,18,16,
17,19,17,16,19,17,18,16,17,18,18,16,18,18,16,16,18,16,19,19,17,19,18,18,17,17,19,17,16,18,18,18,18,18,18,18,17,16,18,17,
17,16,16,19,16,17,19,16,16,19,16,17,17,17,19,18,19,19,16,18,17,17,16,17,19,18,17,16,16,19,17,19,19,19,16,19,16,16,18,16,
17,18,18,18,17,17,19,18,18,17,16,17,16,19,16,16,17,18,16,18,18,18,16,18,17,19,19,18,19,17,17,18,19,16,17,19,19,17,19,19,
17,16,16,19,16,19,16,18,16,16,17,17,18,19,18,19,16,18,19,18,18,16,19,16,16,18,16,16,16,18,16,16,18,17,19,17,17,19,19,18,
17,18,18,18,16,19,17,17,18,16,16,19,17,18,17,18,17,19,18,19,18,17,18,18,18,16,16,18,17,16,16,19,16,18,19,19,19,19,18,17
};

    // 'assets/tileset.png' should be a tileset image, and the tiles indices (0,1,...) must match it.
    if(!map.load("assets/tilemaps/GroundTilemap.png", sf::Vector2u(32, 32), level, 40, 40)){
        throw "ERROR::GAMESTATE::FAILED_TO_LOAD_MAP";
    }
    // Map dimensions (example: 40 x 40 tiles at 32px each)
    const float mapWidth = 40 * 32.f;
    const float mapHeight = 40 * 32.f;
    
    // Create colliders for each edge (or one collider for the whole map and then check bounds)
    // For example, here are four boundaries as thin rectangles:
    float thickness = 10.f;  // thickness of the collider
    
    // Left collider
    colliders.emplace_back(sf::FloatRect({-thickness, 0.f}, {thickness, mapHeight}));
    // Right collider
    colliders.emplace_back(sf::FloatRect({mapWidth, 0.f}, {thickness, mapHeight}));
    // Top collider
    colliders.emplace_back(sf::FloatRect({0.f, -thickness}, {mapWidth, thickness}));
    // Bottom collider
    colliders.emplace_back(sf::FloatRect({0.f, mapHeight}, {mapWidth, thickness}));

    

}

GameState::~GameState()
{
}

void GameState::render(sf::RenderWindow* target){
    target->setView(player.playerView);

    target->draw(map);
    for(auto collider : colliders){
        collider.draw(*target);
    }
    target->draw(player);
    target->draw(inventory);
}

void GameState::update(sf::Time deltaTIme){
    this->updateMousePositions();
    
    sf::FloatRect playerBounds({static_cast<float>(player.getPosition().x  - player.getOrigin().x ),
                                static_cast<float>(player.getPosition().y  - player.getOrigin().y )},{
                                64.f, 64.f}); 

    // Check for collisions against all colliders:
    for(const auto& collider : colliders){
        //std::cout << collider.bounds.position.x << " " << collider.bounds.position.y << " , " << player.getPosition().x << " , " << player.getPosition().y << "\n";
        if(playerBounds.findIntersection(collider.bounds)){
            std::cout << collider.bounds.position.x << " " << collider.bounds.position.y << " , " << playerBounds.position.x << " , " << playerBounds.position.y << "\n";
            //std::cout << &collider << "\n";

            float playerTop = playerBounds.position.y;
            float playerLeft = playerBounds.position.x;
            float playerRight = playerBounds.position.x + playerBounds.size.x;
            float playerBottom = playerBounds.position.y + playerBounds.size.y;

            float colliderTop = collider.bounds.position.y;
            float colliderLeft = collider.bounds.position.x;
            float colliderRight = collider.bounds.position.x + collider.bounds.size.x;
            float colliderBottom = collider.bounds.position.y + collider.bounds.size.y;

            // player bottom
            if(playerBottom > colliderTop && playerBottom < colliderBottom &&
                playerLeft > colliderLeft && playerRight < colliderRight
            )
            {   
                player.isColliding = true;
                player.setPosition(sf::Vector2f({playerBounds.position.x+32 , collider.bounds.position.y - playerBounds.size.y + 32 }));
            }
            // player top
            if(playerTop < colliderBottom && playerTop > colliderTop &&
                playerLeft > colliderLeft && playerRight < colliderRight
            )
            {   
                player.isColliding = true;
                player.setPosition(sf::Vector2f({playerBounds.position.x+32, collider.bounds.position.y + collider.bounds.size.y + playerBounds.size.y - 32 }));
            }
            
        }

        
        
    }

        player.update(deltaTIme);
        player.isColliding = false;
    inventory.setPosition( player.getPosition() + sf::Vector2f(50.f, 50.f));
    
}

void GameState::gui(){
    
}

void GameState::processEvents(const sf::Event event){
    if (const auto keyPressed = event.getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                changeState(stateIndex, 0);
            }
            else if(keyPressed->scancode == sf::Keyboard::Scancode::I){
                inventory.isActive = !inventory.isActive;
            }  
        }
}
