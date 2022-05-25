#include <iostream>
#include "Enemy.h"
#include "Item.h"
#pragma once

/*
Pomysł na bossa który po pokonaniu wyrzucałby dodatkowe itemy
np jakas bron, tarcza albo po prostu by wyswietlane bylo że nasze
atrybuty zostały poprawione
*/


class Boss: public Enemy
{
    private:
        Item special_item;

    public:

        Boss(std::string n, int h, const int wd, int ek, Item &si):Enemy(n, h, wd, ek)
        {
            special_item = si;
        }

        Item get_bitem_info()
        {
            return this->special_item;
        }

        Item drop()
        {
            bool life = this->is_alive();
            if(life == false)
                return this->special_item;
        }

        void regeneration()
        {
            this->health += 1;
        }
};