#include <iostream>
#include "Item.h"

// TODO
// klasa Chest
// param: wszystkie itemki mozliwe do zdobycia w grze
// metoda: randint czy cos ktory wolosowuje jakie itemki beda sie znajdowaly
// w danej chwili w skrzyni
// przetestowac
// rzucac wyjatki


class Chest
{
    /*
    const int item_number;
    Item* items;

    public:
        Chest():item_number(10), items(Item[10]);

        void add_item()
        {
            
            for(int i=0; i<item_number; i++)
            {
                items[i] = Item::Item
            }     
    */
    private:
        Item* items;
        int item_number;

    public:
        Chest():item_number(10)
        {
            items = new Item[10];
        }

        int get_num() {return this->item_number;}

        void add_items()
        {
            items[0] = Item("Kebab laser", 50, 1);
            items[1] = Item("Spear of 1000 moms", 2000, 1);
            items[2] = Item("Photon spear", 20, 2);
            items[3] = Item("Healing tears of Holy Mother", 30, 0);
            items[4] = Item("laser 2", 10, 1);
            items[5] = Item("laser 3", 15, 1);
            items[6] = Item("shield 2", 10, 2);
            items[7] = Item("shield 3", 15, 2);
            items[8] = Item("potion 2", 10, 0);
            items[9] = Item("potion 3", 15, 0);
        }       

    
        Item operator[](int const id)
        {
            return this->items[id];
        }

};