#include "column.hpp"

void runCases(std::vector<Elevator> &elevatorList)
{
    const std::size_t NUMBER_OF_DEMANDS = 2;
    int nFloorDemand_1 = 1;
    int nFloorDemand_2 = 4;
    int nDemands[NUMBER_OF_DEMANDS] = { nFloorDemand_1, nFloorDemand_2 };
    for (std::size_t i = 0; i < elevatorList.size(); ++i) {
        std::cout << "callButtonFloors = " <<  nDemands[i] << "\n";
    }
    
}

struct ListElevators
{
    std::vector<Elevator> elevator;
    int index;
};

int findIdleElevatorsIndexInsideElevatorList(std::vector<Elevator> &elevatorList)
{
    for (std::size_t i = 0; i < elevatorList.size(); ++i) {
        if (elevatorList[i].getDirection() == "IDLE") {
            return i;
        }
    }
    return -1;
}

int findClosestElevatorIndex(std::vector<Elevator> &elevatorList, int requestedFloorNumber, std::string requestedDirection)
{
    int deltaBetweenElevatorAndRequestedFloor = 0;
    int smallestDelta = 0;
    int smallestElevatorId = -1;
    for (std::size_t i = 0; i < elevatorList.size(); ++i) {
        deltaBetweenElevatorAndRequestedFloor = elevatorList[i].getCurrentFloor() - requestedFloorNumber;
        if (deltaBetweenElevatorAndRequestedFloor < 0) {
            deltaBetweenElevatorAndRequestedFloor *= (-1);
        }
        if (i == 0) {
            smallestDelta = deltaBetweenElevatorAndRequestedFloor;
        }
        if (deltaBetweenElevatorAndRequestedFloor == 0) {
            return i;
        } else if (deltaBetweenElevatorAndRequestedFloor < smallestDelta) {
            if (requestedDirection == elevatorList[i].getDirection()) {
                smallestDelta = deltaBetweenElevatorAndRequestedFloor;
                smallestElevatorId = i;
            }
        }
    }
    if (smallestElevatorId < 0) {
        smallestElevatorId = findIdleElevatorsIndexInsideElevatorList(elevatorList);
        if (smallestElevatorId > 0) {
            return smallestElevatorId;
        }
    }
    //if (smallestElevatorId < 0) {
        //findClosestElevator(elevatorList, requestedFloorNumber, requestedDirection);
    //}
    return smallestElevatorId;
}

int main(int argc, char **argv)
{
    int id = 2, nFloors = 10, nColumns = 1;
    int currentFloor = 0;
    std::string direction = "";
   //Column column = new Column(id, nFloors, nColumns);

    const std::size_t N_ELEVATORS = 2;

    int id_ = 0;
    
    Elevator elevatorA(currentFloor, direction, 1, "A");
    elevatorA.setCurrentFloor(5);
    elevatorA.setDirection("IDLE");
    elevatorA.setName("A");

    Elevator elevatorB(currentFloor, direction, 2, "B");
    elevatorB.setCurrentFloor(9);
    elevatorB.setDirection("DOWN");
    elevatorA.setName("B");

    Elevator list[N_ELEVATORS] = { elevatorA, elevatorB };

    std::vector<Elevator> elevatorList;
    for (std::size_t i = 0; i < N_ELEVATORS; ++i) {
        elevatorList.push_back(list[i]);
        //std::cout << "ids push back " << elevatorList[i].getId() << "\n";
    }
    Column column(id, nFloors, nColumns, elevatorList);
    //column.setId(id);
    column.setNumberOfFloors(nFloors);
    column.setNumberOfColumns(nColumns);
    std::cout << "Number of Floors = " << column.getNumberOfFloors() << std::endl;
    //runCases();
    //Elevator chosenElevator = findClosestElevator(elevatorList, 8, "DOWN");
    int chosenElevatorIndex = findClosestElevatorIndex(elevatorList, 8, "DOWN");
    std::cout << "chosenElevatorIndex = "  << chosenElevatorIndex << "\n";
    for (std::size_t i = 0; i < N_ELEVATORS; ++i) {
        if (list[i].getId() == chosenElevatorIndex) {
            std::cout << "id = " << list[i].getId() << " " << " " << list[i].getName() << "\n";
        }
    }
    return 0;
}