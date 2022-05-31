#include <iostream>
#include "Person.h"
#include "Enemy.h"

#pragma once
using namespace std;


class Player : public Person
{
    private:
        const int max_health = 100;
        int weapon_damage;
        int shield;

    public:
        Player(int h, int wd, int sh):Person(h)
        {
            weapon_damage = wd;
            shield = sh;
        }

        void set_wd(int wd);
        void set_sh(int sh);
        int get_h() const {return this->health;}
        const int get_mh() const {return this->max_health;}
        int get_wd() const {return this->weapon_damage;}
        int get_sh() const {return this->shield;}
        void pick_up(const int& new_wd);
        void heal(const int &potion);
        int attack_kind(Enemy& enemy, const int& akind);
};
