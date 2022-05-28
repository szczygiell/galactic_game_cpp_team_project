#include <iostream>
#include <stdlib.h>
#include <tuple>
#include "Item.h"
#pragma once

class Chest
{

    private:
        Item* items;
        int item_number;

    public:

        Chest():item_number(10)
        {
            items = new Item[10];
        }
        Chest(int ammount):item_number(ammount)
        {
            items = new Item[item_number];
        }
        int get_num() {return this->item_number;}

        void add_items();
        Item operator[](int const id){return this->items[id];}
        Item pop_item();
};