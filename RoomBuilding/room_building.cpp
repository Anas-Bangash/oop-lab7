#include "room_building.h"
#include<iostream>
#include<string>

Room::Room(): roomNumber(0){}
void Room::setRoomNumber(int rN)
{
    roomNumber = rN;
}
int Room::getRoomNumber()
{
    return roomNumber;
}
bool Room::isEvenRoom()
{
    if(roomNumber!=0 && roomNumber%2==0)
    {
        return true;
    }
    else{return false;}
}
Building::Building(Room room[3]): buildingName("")
{
    for(int i=0; i<3; i++)
    {
        this->room[i] = room[i];
    }
} 
void Building::setBuildingName(string bN)
{
    buildingName = bN;
}
string Building::getBuildingName()
{
    return buildingName;
}
bool Building::hasEvenRoom()
{
    for(int i=0; i<3; i++)
    {
        if(room[i].isEvenRoom)
        {
            return true;
        }
    }
    return false;
}
