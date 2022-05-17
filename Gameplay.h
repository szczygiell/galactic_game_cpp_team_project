#include <iostream>
#include "Player.h"
#include "Enemy.h"
#pragma once


class Gameplay
{
    private:


    public:
        Gameplay(){}
        tuple<int, int, int, int, int, int> get_state(Player& player, Enemy& enemy);
        void disp_level(Player& player, Enemy& enemy);
};