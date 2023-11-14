#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    enum class ItemType {
        KEY,
        WEAPON,
        CONSUMABLE,
       
    };

    std::string name;
    std::string description;
    ItemType type;

    
    Item(std::string name, std::string description, ItemType type);

    
    void use();

    
    void inspect() const;
};

#endif 
