#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Chest.h"
#pragma once


class Gameplay
{
    private:


    public:
        Gameplay(){}
        tuple<int, int, int, int, int, int> get_state(Player& player, Enemy& enemy);
        void disp_level(Player& player, Enemy& enemy);

        tuple<int, int, int, int> get_state_chest(Player& player);
        void disp_chest(Player& player); // jako drugi parametr będzie musiało być: ', Chest& chest'
};