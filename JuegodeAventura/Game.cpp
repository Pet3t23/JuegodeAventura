#include "Game.h"
#include <iostream>

Game::Game() : currentRoomIndex(0) {}

void Game::move(int roomIndex) {
    if (roomIndex >= 0 && roomIndex < rooms.size()) {
        currentRoomIndex = roomIndex;
        exploreRoom();
    }
    else {
        std::cout << "No puedes ir en esa dirección.\n";
    }
}

void Game::exploreRoom() {
    Room currentRoom = rooms[currentRoomIndex];
    currentRoom.describeRoomState();
    
}
