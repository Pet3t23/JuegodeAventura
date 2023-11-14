
#include "Enemy.h"
#include "Player.h"
#include <iostream>

Enemy::Enemy(std::string name, int health, int damage, int attackDamage)
    : name(std::move(name)), health(health), damage(damage), attackDamage(attackDamage) {}

void Enemy::attack(Player& player) {
    std::cout << name << " ataca a " << player.getName() << ".\n";
    player.receiveDamage(attackDamage);
}
