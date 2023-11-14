
#ifndef PLAYER_H
#define PLAYER_H

#include "Item.h"
#include "Enemy.h"
#include <string>
#include <vector>

class Player {
public:
    std::string name;
    int health;
    int lives;
    std::vector<Item> inventory;

    Player(std::string playerName, int initialHealth, int initialLives);
    void pickUpItem(const Item& newItem);
    void useItem(const std::string& itemName);
    void attack(Enemy& enemy);
    void receiveDamage(int damage);
    void loseLife();
    std::string getName() const;  
};

#endif 
