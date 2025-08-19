#include "room_building.h"
#include<iostream>
#include<string>

using namespace std;

int main() {
    // Create Room objects
    Room rooms[3];
    for(int i = 0; i < 3; ++i) 
    {
        int roomNumber;
        cout << "Enter room number for Room " << i + 1 << ": ";
        cin >> roomNumber;
        rooms[i].setRoomNumber(roomNumber); 
    }

    Building building(rooms);
    building.setBuildingName("Science Block");

    std::cout << "Building Name: " << building.getBuildingName() << std::endl;

    for (int i = 0; i < 3; ++i) {
        std::cout << "Room " << i + 1 << " Number: " << rooms[i].getRoomNumber();
        if (rooms[i].isEvenRoom()) {
            std::cout << " (Even)";
        }
        std::cout << std::endl;
    }

    if (building.hasEvenRoom()) {
        std::cout << "The building has at least one even-numbered room." << std::endl;
    } else {
        std::cout << "The building does not have any even-numbered rooms." << std::endl;
    }

    return 0;
}
