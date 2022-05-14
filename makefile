tests: tests.o Player.o Person.o
	g++ -o tests.out tests.o Player.o Person.o

tests.o: tests.cpp
	g++ -c tests.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

Person.o: Person.cpp
	g++ -c Person.cpp

clean:
	rm -f tests Player.o Person.o tests.exe tests.o
