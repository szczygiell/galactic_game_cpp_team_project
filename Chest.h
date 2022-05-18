#include <iostream>
#include <stdlib.h>
#include <tuple>
#include "Item.h"
#pragma once

// TODO
// klasa Chest
// param: wszystkie itemki mozliwe do zdobycia w grze
// metoda: randint czy cos ktory wolosowuje jakie itemki beda sie znajdowaly
// w danej chwili w skrzyni
// przetestowac
// rzucac wyjatki


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

        int get_num() {return this->item_number;}

        void add_items();

        // propozycja żeby zrobić skrzynię która miała by trzy kontenery w sobie
        // np chest[0] posidałby bron chest[1] tarcze itd
        // i dopiero w tych chest[i] bylo by kilka elementow danego rodzaju
        // mam wrazenie ze wtedy ltwiej bedzie to przeniesc do gameplay

        Item operator[](int const id){return this->items[id];}
        std::tuple<Item, Item, Item> generate_chest();
};