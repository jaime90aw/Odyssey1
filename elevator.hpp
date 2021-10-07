#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <iostream>
#include <string>
#include <cstdint>

class Elevator {
public:
    Elevator(int currentFloor, std::string direction, int id, std::string name);
    void setCurrentFloor(int currentFloor);
    void setDirection(std::string direction);
    void setFloorRequestButton(int floorRequestButton);
    void setDoors(bool doors);
    void setIdleMode(bool isIdle);
    void setName(std::string name);


    int getCurrentFloor();
    std::string getDirection();
    int getFloorRequestButton();
    bool getDoors();
    bool getIdleMode();
    int getId();
    std::string getName();


private:
    static int _id;
    int _thisId;
    std::string _name;
    std::string _direction;         // UP or DOWN or IDLE
    int _currentFloor;              // Current floor of the elevator
    int _floorRequestButton;        // Pressed floor button inside the elevator
    bool _doors;                    // Are the elevator doors open or closed?
    bool _isIdle;                   // Is the elevator on idle mode?
    int _toFloorNumber;             // The floor where the elevator is headed
    int _scoreGivenToElevator;      // Score given to the elevator for determining how satisfying its position is vis-a-vis the user
};

#endif // ELEVATOR_H