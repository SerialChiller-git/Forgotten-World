#pragma once
#include <vector>
#include "Item.h"
#include <iostream>
#include <filesystem>
#include <SFML/Graphics.hpp>

class Invetory{
public:

    sf::Font font;
    Invetory(){
        initialize();
    }

    void initialize(){
        if (!font.openFromFile("assets/yoster.ttf")) {
            std::cerr << "Error loading font\n";
            return;
        }
    }

    void addItem(const Item& item){
        items.push_back(item);
    }
    void removeItem(int id){
        int index = -1;
        for(int i = 0; i < items.size(); i++){
            if(items[i].id == id){
                index = i;
                break;
            }
        }
        if(index != -1){
            items.erase(items.begin() + index);
        }
        return;
    }
    const std::vector<Item>& getItems() const {
        return items;
    }

private:
    std::vector<Item> items;
};