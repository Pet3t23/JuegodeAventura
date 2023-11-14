#include <iostream>
#include "Room.h"
#include "Item.h"
#include "Enemy.h"
#include "Game.h"
#include "Player.h"

int main() {
    std::string playerName;
    std::cout << "Estás atrapado en una casa misteriosa. Para escapar, debes llegar a la habitación final.\n";
    std::cout << "¡Buena suerte en tu aventura!\n";
    std::cout << "Por favor, ingresa tu nombre: ";

    std::cin >> playerName;

    int initialHealth = 100;
    int initialLives = 3;

    Player player(playerName, 100, 3);

    Room inicio("Inicio", "El comienzo de tu aventura.");
    Room salaDeEstar("Sala de estar", "Una habitación acogedora con un sofá y una chimenea.");
    Room cocina("Cocina", "Un lugar donde se preparan deliciosas comidas.");
    Room habitacionPrincipal("Habitación principal", "El corazón de la casa, con una cama grande y cómoda.");
    Room sotano("Sótano", "Un lugar oscuro y misterioso.");
    Room salaDeArmas("Sala de armas", "Llena de armas antiguas y herrumbrosas.");
    Room habitacionDeLimpieza("Habitación de limpieza", "Llena de utensilios de limpieza y trapeadores.");
    Room campoDeTiro("Campo de tiro", "Donde se practica la puntería con arcos y flechas.");
    Room calabozo("Calabozo", "Un lugar aterrador con celdas vacías.");
    Room salaDeTortura("Sala de tortura", "Un lugar siniestro con herramientas extrañas.");

    Item key("Llave", "Abre una puerta misteriosa", Item::ItemType::KEY);
    inicio.addItem(key);

    Item key2("Llave dorada", "Abre una puerta especial", Item::ItemType::KEY);
    habitacionPrincipal.addItem(key2);

    Item bow("Arco y flechas", "Un arma a distancia", Item::ItemType::WEAPON);
    campoDeTiro.addItem(bow);

    Enemy spider("Araña", 20, 5, 8); 
    salaDeEstar.addEnemy(spider);

    Enemy zombie("Zombi", 30, 8, 10);
    cocina.addEnemy(zombie);

    Enemy ghost("Fantasma", 25, 6, 10);
    habitacionPrincipal.addEnemy(ghost);

    Enemy skeleton("Esqueleto", 35, 7, 10);
    sotano.addEnemy(skeleton);

    Enemy orc("Orco", 40, 9, 10);
    salaDeArmas.addEnemy(orc);

    Enemy boss("Jefe final", 100, 15, 20);
    calabozo.addEnemy(boss);

    
    Game adventure;
    adventure.rooms.push_back(inicio);
    adventure.rooms.push_back(salaDeEstar);
    adventure.rooms.push_back(cocina);
    adventure.rooms.push_back(habitacionPrincipal);
    adventure.rooms.push_back(sotano);
    adventure.rooms.push_back(salaDeArmas);
    adventure.rooms.push_back(habitacionDeLimpieza);
    adventure.rooms.push_back(campoDeTiro);
    adventure.rooms.push_back(calabozo);
    adventure.rooms.push_back(salaDeTortura);

    int currentRoom = 0;
    const int finalRoomIndex = 9;

    while (true) {
        adventure.rooms[currentRoom].describeRoomState();
        if (currentRoom == finalRoomIndex) {
            std::cout << "¡Has llegado a la habitación final! ¡Has escapado de la casa misteriosa!\n";
            std::cout << "¡Fin de la historia!\n";
            break; 
        }

        std::cout << "¿Qué deseas hacer? (1. Explorar, 2. Recoger ítems, 3. Enfrentar enemigos, 4. Cambiar de habitación, 5. Salir): ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Explorando...\n";
            adventure.rooms[currentRoom].describeRoomState();
            break;

        case 2:
            std::cout << "Recogiendo ítems...\n";
            if (!adventure.rooms[currentRoom].items.empty()) {
                std::cout << "Elige un ítem a recoger:\n";
                int index = 1;
                for (const auto& item : adventure.rooms[currentRoom].items) {
                    std::cout << index << ". " << item.name << " - " << item.description << "\n";
                    index++;
                }
                int itemChoice;
                std::cin >> itemChoice;

                if (itemChoice >= 1 && itemChoice <= adventure.rooms[currentRoom].items.size()) {
                    player.pickUpItem(adventure.rooms[currentRoom].items[itemChoice - 1]);
                    std::cout << "¡Has recogido " << adventure.rooms[currentRoom].items[itemChoice - 1].name << "!\n";
                    adventure.rooms[currentRoom].removeItem(adventure.rooms[currentRoom].items[itemChoice - 1].name);
                }
                else {
                    std::cout << "Selección de ítem no válida.\n";
                }
            }
            else {
                std::cout << "No hay ítems en esta habitación.\n";
            }
            break;

        case 3:
            std::cout << "Enfrentando enemigos...\n";
            if (!adventure.rooms[currentRoom].enemies.empty()) {
                std::cout << "Elige un enemigo a atacar:\n";
                int index = 1;
                for (const auto& enemy : adventure.rooms[currentRoom].enemies) {
                    std::cout << index << ". " << enemy.name << " (Salud: " << enemy.health << ")\n";
                    index++;
                }
                int enemyChoice;
                std::cin >> enemyChoice;

                if (enemyChoice >= 1 && enemyChoice <= adventure.rooms[currentRoom].enemies.size()) {
                    player.attack(adventure.rooms[currentRoom].enemies[enemyChoice - 1]);
                    
                    for (auto& enemy : adventure.rooms[currentRoom].enemies) {
                        enemy.attack(player);
                    }
                }
                else {
                    std::cout << "Selección de enemigo no válida.\n";
                }
            }
            else {
                std::cout << "No hay enemigos en esta habitación.\n";
            }
            break;
        case 4:
            std::cout << "Cambiando de habitación...\n";
            currentRoom = (currentRoom + 1) % adventure.rooms.size(); 
            break;
        case 5:
            std::cout << "Saliendo del juego. ¡Hasta luego!\n";
            return 0;
        default:
            std::cout << "Opción no válida.\n";
        }
    }

    return 0;
}
