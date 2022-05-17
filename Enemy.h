#include <iostream>
#include "Person.h"
#pragma once

//TODO
// klasa enemy DONE
// param: bron (const), z jakiego regionu planety DONE
// gettery i settery DONE
// pamietac o stworzeniu pliku cpp i zmodyfikowaniu makefila DONE
// przetestowac DONE
// rzucac wyjatki
// destruktor jesli ma 0 zdrowia

class Enemy: public Person
{
    private:
        int eweapon_damage;
        int ekind;
        //which value represents which ekind:
        //0: fire
        //1: water
        //2: earth
        //3: air
    
    public:
        Enemy(int h, const int wd, int ek):Person(h)
        {
            eweapon_damage = wd;
            ekind = ek;
        }

        int get_ehealth() {return this->health;};
        int get_ewd() {return this->eweapon_damage;};
        int get_ekind() {return this->ekind;};

        void set_ehealth(int& new_health)
        {
            this->health += new_health;
        }
};