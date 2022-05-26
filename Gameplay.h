#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Chest.h"
#include "Boss.h"
#pragma once


class Gameplay
{
    private:


    public:
        Gameplay(){}
        void disp_battle(Player& player, Enemy& enemy, int& round);
        void battle(Player &player, Enemy &enemy);
        void boss_battle(Player &player, Boss &boss);
        void disp_chest(Player& player, Chest& chest);
        void draw_battle(Player &player, int const& ek);
};

void disp_border();
Enemy generate_enemy(int const& ek);
std::string draw_rand_name(int const& ek);