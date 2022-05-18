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
    protected:
        int eweapon_damage;
        int ekind;
        //which value represents which ekind:
        //0: fire
        //1: water
        //2: earth
        //3: air

        // czy nie lepiej byloby ograniczyć się do dwóch rodzajów?
        // coś w stylu wiedzmina jeden miecz na potwory drugi na ludzi xd

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

        void take_damege(const int& damage)
        {
            this->health -= damage;
        }

        bool dodge()
        {
            // pomysł jest następujący:
            // możemy dodać szansę na unik ataku od bohatera.
            // w trakcie każdego ataku włączałaby się ta funkcja i sprawdzała czy
            // przeciwnik uniknął ataku czy nie
            srand(time(0));
            int chance = rand() % 10;
            if(chance == 1)
                return true;
            return false;
        }

        bool is_alive()
        {
            if(this->health <= 0)
                return true;
            return false;
        }
};