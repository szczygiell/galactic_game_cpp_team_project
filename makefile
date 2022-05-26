tests: tests.o Player.o Person.o Gameplay.o Chest.o
	g++ -o tests.out tests.o Player.o Person.o Gameplay.o Chest.o

tests.o: tests.cpp Player.h Person.h Enemy.h Item.h Action.h Boss.h Gameplay.h Chest.h
	g++ -c tests.cpp

Chest.o: Chest.cpp
	g++ -c Chest.cpp

Gameplay.o: Gameplay.cpp Player.h Enemy.h Chest.h Boss.h
	g++ -c Gameplay.cpp

Item.o: Item.cpp
	g++ -c Item.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

Person.o: Person.cpp
	g++ -c Person.cpp

clean:
	rm -f tests.exe Player.o Person.o Item.o Gameplay.o tests.o* Chest.o
