#ifndef ROOM_BUILDING_H
#define ROOM_BUILDING_H

#include<iostream>
#include<string>

using namespace std;

class Room
{
    int roomNumber;
    public:
    Room();
    void setRoomNumber(int rN);
    int getRoomNumber();
    bool isEvenRoom();
};
class Building
{
    string buildingName;
    Room room[3];
    public:
    building();
    building(Room room[3]);
    void setBuildingName(string bN);
    string getBuildingName();
    bool hasEvenRoom();
};

#endif // ROOM_BUILDING_H