#ifndef COLUMN_H
#define COLUMN_H

#include <iostream>
#include <string>
#include <vector>
#include "elevator.hpp"

class Column {
    //int _id;
    int _numberOfFloors;
    int _numberOfColumns;
    int _callButtonFloor;
    std::vector<int> _listOfCallButtonFloors;
    std::vector<Elevator> _elevatorList;
    
public:
    Column(int id, int numberOfFloors, int numberOfColumns, std::vector<Elevator> &elevatorList);
    //void setId(int id);
    void setNumberOfFloors(int numberOfFloors);
    void setNumberOfColumns(int numberOfColumns);
    //int getId();
    int getNumberOfFloors();
    int getNumberOfColumns();
    std::vector<Elevator> getElevatorList();
    Elevator getClosestElevator();
   Column();
};

#endif // COLUMN_H