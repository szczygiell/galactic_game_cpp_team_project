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
        tuple<int, int, int, int, int, int> get_state(Player& player, Enemy& enemy);
        void disp_battle(Player& player, Enemy& enemy, int& round);
        void battle(Player &player, Enemy &enemy);
        void boss_battle(Player &player, Boss &boss);
        tuple<int, int, int, int> get_state_chest(Player& player);
        void disp_chest(Player& player); // jako drugi parametr będzie musiało być: ', Chest& chest'
};