#include <iostream>
#include "Person.h"

//TODO
// klasa enemy
// param: bron (const), z jakiego regionu planety
// gettery i settery
// pamietac o stworzeniu pliku cpp i zmodyfikowaniu makefila
// przetestowac
// rzucac wyjatki
// destruktor jesli ma 0 zdrowia

class Enemy: public Person
{
    private:
        int weapon_damage;
        int ekind;
        //which value represents which ekind:
        //0: fire
        //1: water
        //2: earth
        //3: air
    
    public:
        Enemy(int h, const int wd, int ek):Person(h)
        {
            health = h;
            weapon_damage = wd;
            ekind = ek;
        }

};