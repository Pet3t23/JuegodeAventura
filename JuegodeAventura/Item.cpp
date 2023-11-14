#include "Item.h"
#include <iostream>


Item::Item(std::string name, std::string description, ItemType type)
    : name(std::move(name)), description(std::move(description)), type(type) {}


void Item::use() {
    switch (type) {
    case ItemType::KEY:
        std::cout << "Has usado la llave.\n";
        
        break;
    case ItemType::WEAPON:
        std::cout << "Has equipado el arma.\n";
        
        break;
    case ItemType::CONSUMABLE:
        std::cout << "Has usado el objeto consumible.\n";
        
        break;
        
    }
}


void Item::inspect() const {
    std::cout << "Nombre: " << name << "\n";
    std::cout << "Descripción: " << description << "\n";
   
}
