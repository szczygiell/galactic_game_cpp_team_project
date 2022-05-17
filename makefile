tests: tests.o Player.o Person.o Gameplay.o
	g++ -o tests.out tests.o Player.o Person.o Gameplay.o

tests.o: tests.cpp Player.h Person.h Enemy.h Item.h Chest.h Action.h Gameplay.h
	g++ -c tests.cpp

Gameplay.o: Gameplay.cpp Player.h Enemy.h
	g++ -c Gameplay.cpp

Item.o: Item.cpp
	g++ -c Item.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

Person.o: Person.cpp
	g++ -c Person.cpp

clean:
	rm -f tests.o* Player.o Person.o Item.o Gameplay.o tests.exe