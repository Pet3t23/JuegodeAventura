#include "Room.h"
#include <iostream>

Room::Room(std::string name, std::string description)
    : name(std::move(name)), description(std::move(description)) {}

void Room::addItem(const Item& newItem) {
    items.push_back(newItem);
}

void Room::removeItem(const std::string& itemName) {
    items.erase(std::remove_if(items.begin(), items.end(),
        [&](const Item& item) { return item.name == itemName; }),
        items.end());
}

void Room::addEnemy(const Enemy& newEnemy) {
    enemies.push_back(newEnemy);
}

void Room::removeEnemy(const std::string& enemyName) {
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
        [&](const Enemy& enemy) { return enemy.name == enemyName; }),
        enemies.end());
}

void Room::describeRoomState() const {
    std::cout << "Estás en " << name << ".\n";
    std::cout << description << "\n";

    if (!items.empty()) {
        std::cout << "Items disponibles en este cuarto:\n";
        for (const auto& item : items) {
            std::cout << "- " << item.name << ": " << item.description << "\n";
        }
    }
    else {
        std::cout << "No hay items en este cuarto.\n";
    }

    if (!enemies.empty()) {
        std::cout << "¡Enemigos detectados en este cuarto!\n";
        for (const auto& enemy : enemies) {
            std::cout << "- Enemigo: " << enemy.name << " (Salud: " << enemy.health << ")\n";
        }
    }
    else {
        std::cout << "No hay enemigos en este cuarto.\n";
    }
}
