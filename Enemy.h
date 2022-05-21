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
        Enemy()
        {}

        int get_ehealth() {return this->health;};
        int get_ewd() {return this->eweapon_damage;};
        int get_ekind() {return this->ekind;};

        void set_ehealth(int& new_health)
        {
            this->health += new_health;
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

        std::string get_name()
        {
            srand(time(0));
            int temp = rand() % 3;
            if(ekind == 0)
                if(temp = 0)
                    return "Ognisty żywiołak";
                if(temp = 1)
                    return "Ognisty pies";
                if(temp = 2)
                    return "Ognisty smok";
            if(ekind == 1)
                return "Baba wodna";
            if(ekind == 2)
                return "Twoja stara";
            if(ekind == 3)
                return "Twój stary";
            else
                return "nieznany gatunek";
        }

        int deal_dmg()
        {
            srand(time(0));
            int dmg = rand() % 11;
            return eweapon_damage - dmg;
        }
};

// Enemy generate_enemy(int& level, int& ekind)
// {
    // srand(time(0));
    // int ehealth = rand() % (10- level)*5;
    // int ewd = rand() % (10 - level);
    // return Enemy(ehealth, ewd, ekind);
//
// }
