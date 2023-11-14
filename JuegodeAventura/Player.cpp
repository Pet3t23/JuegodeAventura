
#include "Player.h"
#include <iostream>

Player::Player(std::string playerName, int initialHealth, int initialLives)
    : name(std::move(playerName)), health(initialHealth), lives(initialLives) {}

void Player::pickUpItem(const Item& newItem) {
    inventory.push_back(newItem);
}

void Player::useItem(const std::string& itemName) {
    auto itemIter = std::find_if(inventory.begin(), inventory.end(),
        [&](const Item& item) { return item.name == itemName; });

    if (itemIter != inventory.end()) {
        std::cout << "Has usado el item: " << itemName << ".\n";
        inventory.erase(itemIter);
    }
    else {
        std::cout << "No tienes ese item en tu inventario.\n";
    }
}

void Player::attack(Enemy& enemy) {
    enemy.health -= 10;
    std::cout << "¡Has atacado a " << enemy.name << "!\n";

    if (enemy.health <= 0) {
        std::cout << enemy.name << " ha sido derrotado.\n";
    }
    else {
        std::cout << enemy.name << " te ataca. ";
        receiveDamage(enemy.attackDamage);
    }
}

void Player::receiveDamage(int damage) {
    health -= damage;
    std::cout << "Recibes " << damage << " puntos de daño. Salud actual: " << health << "\n";

    if (health <= 0) {
        loseLife();
    }
}

void Player::loseLife() {
    lives--;

    if (lives > 0) {
        std::cout << "Te queda(n) " << lives << " vida(s). Reiniciando desde el último punto de control.\n";
        health = 100;
    }
    else {
        std::cout << "¡Has perdido todas tus vidas! Fin del juego.\n";
    }
}

std::string Player::getName() const {
    return name;
}
