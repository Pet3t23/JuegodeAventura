#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Player; 

class Enemy {
public:
    std::string name;
    int health;
    int damage;
    int attackDamage;

    Enemy(std::string name, int health, int damage, int attackDamage);
    void attack(Player& player);  
};

#endif 
