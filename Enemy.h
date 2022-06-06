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
        //1: PIPR-2
        //2: ALIN-ANA
        //3: POEL-4.5P

    public:
        Enemy(std::string n, int h, const int wd, int ek):Person(h)
        {
            name = n;
            eweapon_damage = wd;
            ekind = ek;
        }
        Enemy()
        {}
        ~Enemy() { }

        std::string get_name() const {return this->name;}
        int get_ehealth() const {return this->health;}
        int get_ewd() const {return this->eweapon_damage;}
        int get_ekind() const {return this->ekind;}

        void set_ehealth(int& new_health)
        {
            this->health += new_health;
        }

        bool dodge() const
        {
            srand(time(0));
            int chance = rand() % 10;
            if(chance == 1)
                return true;
            return false;
        }

        int deal_dmg() const
        {
            srand(time(0));
            int dmg = rand() % 11;
            return abs(eweapon_damage - dmg);
        }
};
