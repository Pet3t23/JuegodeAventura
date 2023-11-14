#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Room.h"

class Game {
public:
    std::vector<Room> rooms;
    int currentRoomIndex;

    Game();

    void move(int roomIndex);
    void exploreRoom();
};

#endif 
