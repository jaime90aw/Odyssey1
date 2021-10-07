CC = g++
SOURCES = column.cpp elevator.cpp
HEADERS = column.hpp elevator.hpp
OBJECTS = main.o column.o elevator.o
DIR = .

main.exe: $(OBJECTS)
	CC -o main.exe $(OBJECTS)

main.o: main.cpp $(SOURCES)
	CC -c main.cpp

column.o: column.cpp column.hpp
	CC -c column.cpp

elevator.o: elevator.cpp elevator.hpp
	CC -c elevator.cpp

clean:
	rm $(OBJECTS) main.exe