#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "Item.h"
#include "Enemy.h"

class Room {
public:
    std::string name;
    std::string description;
    std::vector<Item> items;
    std::vector<Enemy> enemies;

    Room(std::string name, std::string description);

    void addItem(const Item& newItem);
    void removeItem(const std::string& itemName);
    void addEnemy(const Enemy& newEnemy);
    void removeEnemy(const std::string& enemyName);

    void describeRoomState() const;
};

#endif 
