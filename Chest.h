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
            // 0: health
            // 1: wd
            // 2: sh
            items = new Item[10];
            items[0] = Item("Astro Toy Box", -5, 1);
            items[1] = Item("Spear of 1000 moons", 20, 1);
            items[2] = Item("Photon spear", -10, 1);
            items[3] = Item("Healing tears of Holy Mother", 30, 0);
            items[4] = Item("4-dimensional Spikes", -5, 1);
            items[5] = Item("Sharp Lightbringer", 15, 1);
            items[6] = Item("Space Cola", 10, 2);
            items[7] = Item("Quantum Guardian Protection", 15, 2);
            items[8] = Item("Black Hole Elixir", 10, 0);
            items[9] = Item("Tears of a dying star", 15, 0);
        }
        // Chest(int ammount):item_number(ammount)
        // {
        //     items = new Item[item_number];
        // }
        int get_num() {return this->item_number;}

        // void add_items();
        Item operator[](int const id){return this->items[id];}
        Item pop_item();
};