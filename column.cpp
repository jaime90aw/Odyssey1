#include "column.hpp"
#include "elevator.hpp"

Column::Column(int id, int numberOfFloors, int numberOfColumns, std::vector<Elevator> &elevatorList)
:/* _id(id), */ _numberOfFloors(numberOfFloors), _numberOfColumns(numberOfColumns), _elevatorList(elevatorList)
{
    //std::vector<Elevator> elevatorList;
    _listOfCallButtonFloors.clear();
    _callButtonFloor = 0; 
}

//void Column::setId(int id) { _id = id; }
void Column::setNumberOfFloors(int numberOfFloors) { _numberOfFloors = numberOfFloors; }
void Column::setNumberOfColumns(int numberOfColumns) { _numberOfColumns = numberOfColumns; }

//int Column::getId() { return _id; }
int Column::getNumberOfFloors() { return _numberOfFloors; }
int Column::getNumberOfColumns() { return _numberOfColumns; }
std::vector<Elevator> Column::getElevatorList() { return _elevatorList; }

Elevator Column::getClosestElevator()
{
    int nFloorDifferenceBetweenUserAndElevator = 0;
    int smallestDifferenceBetweenUserAndElevator = 0;
    for (std::size_t i = 0; i < _elevatorList.size(); ++i) {
        nFloorDifferenceBetweenUserAndElevator = _callButtonFloor - _elevatorList[i].getCurrentFloor(); 
        if (nFloorDifferenceBetweenUserAndElevator < 0) { nFloorDifferenceBetweenUserAndElevator *= (-1); }
        if (_elevatorList[i].getIdleMode() == true) {
           if (nFloorDifferenceBetweenUserAndElevator < smallestDifferenceBetweenUserAndElevator) {
               smallestDifferenceBetweenUserAndElevator = nFloorDifferenceBetweenUserAndElevator;
               return _elevatorList[i];
           }
        } else {
        }
    }
}
