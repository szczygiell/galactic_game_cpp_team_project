tests: tests.o Player.o Person.o
	g++ -o tests tests.o Player.o Person.o

tests.o: tests.cpp Player.h Person.h Enemy.h
	g++ -c tests.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

Person.o: Person.cpp
	g++ -c Person.cpp

clean:
	rm -f tests Player.o Person.o