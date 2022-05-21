tests: tests.o Player.o Person.o Gameplay.o Chest.o
	g++ -o tests.out tests.o Player.o Person.o Gameplay.o Chest.o

main_game: main_game.o Player.o Person.o Gameplay.o Chest.o
	g++ -o main_game.out main_game.o Player.o Person.o Gameplay.o Chest.o

tests.o: tests.cpp Player.h Person.h Enemy.h Item.h Action.h Boss.h Gameplay.h Chest.h
	g++ -c tests.cpp

main_game.o: main_game.cpp Player.h Person.h Enemy.h Item.h Action.h Boss.h Gameplay.h Chest.h
	g++ -c main_game.cpp

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
	rm -f tests.out Player.o Person.o Item.o Gameplay.o tests.exe Chest.o main_game.out main_game.o
