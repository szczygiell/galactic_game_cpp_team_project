#include <iostream>
#pragma once
#include "Person.h"

using namespace std;


class Player : public Person
{
    private:
        int max_health;
        int weapon_damage;
        int shield; 

    public:
        Player(int h, int mh, int wd, int sh):Person(h)
        {
            max_health = mh;
            weapon_damage = wd;
            shield = sh;
        }
        
        void set_mh(int mh);
        void set_wd(int wd);
        void set_sh(int sh);
        int get_mh() {return this->max_health;};
        int get_wd() {return this->weapon_damage;};
        int get_sh() {return this->shield;};
        void pick_up(const int& new_wd);
        void heal(const int &potion);
};
        