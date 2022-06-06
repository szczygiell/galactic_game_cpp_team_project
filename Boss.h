#include <iostream>
#include "Enemy.h"
#include "Item.h"
#pragma once


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