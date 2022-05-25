#include <iostream>
#include "Person.h"
#pragma once

class Enemy: public Person
{
    protected:
        std::string name;
        int eweapon_damage;
        int ekind;
        //which value represents the planet:
        //0: PIPR-2
        //1: ALIN-ANA
        //2: POEL-4.5P
        //3: PROI-25

    public:
        Enemy(std::string n, int h, const int wd, int ek):Person(h)
        {
            name = n;
            eweapon_damage = wd;
            ekind = ek;
        }
        Enemy()
        {}

        std::string get_name() {return this->name;}
        int get_ehealth() {return this->health;}
        int get_ewd() {return this->eweapon_damage;}
        int get_ekind() {return this->ekind;}

        void set_ehealth(int& new_health)
        {
            this->health += new_health;
        }

        bool dodge()
        {
            srand(time(0));
            int chance = rand() % 10;
            if(chance == 1)
                return true;
            return false;
        }

        int deal_dmg()
        {
            srand(time(0));
            int dmg = rand() % 11;
            return abs(eweapon_damage - dmg);
        }
};
