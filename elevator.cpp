#include "elevator.hpp"

Elevator::Elevator(int currentFloor, std::string direction, int id, std::string name): _currentFloor(currentFloor), _direction(direction), _thisId(id), _name(name) 
{
    _floorRequestButton = 0;
    _doors = false;
    _isIdle = true;
    _toFloorNumber = 0;
}

void Elevator::setCurrentFloor(int currentFloor) { _currentFloor = currentFloor; }
void Elevator::setDirection(std::string direction) { _direction = direction; }
void Elevator::setFloorRequestButton(int floorRequestButton) { _floorRequestButton = floorRequestButton; }
void Elevator::setDoors(bool doors) { _doors = doors; }
void Elevator::setIdleMode(bool isIdle) { _isIdle = isIdle; }
void Elevator::setName(std::string name) { _name = name; }

int Elevator::getCurrentFloor() { return _currentFloor; }
std::string Elevator::getDirection() { return _direction; }
int Elevator::getFloorRequestButton() { return _floorRequestButton; }
bool Elevator::getDoors() { return _doors; }
bool Elevator::getIdleMode() { return _isIdle; }
int Elevator::getId() { return _thisId; }
std::string Elevator::getName() { return _name; }
