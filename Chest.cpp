#include "Chest.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void Chest::add_items()
{
    items[0] = Item("Kebab laser", 50, 1);
    items[1] = Item("Spear of 1000 moons", 2000, 1);
    items[2] = Item("Photon spear", 20, 2);
    items[3] = Item("Healing tears of Holy Mother", 30, 0);
    items[4] = Item("laser 2", 10, 1);
    items[5] = Item("laser 3", 15, 1);
    items[6] = Item("shield 2", 10, 2);
    items[7] = Item("shield 3", 15, 2);
    items[8] = Item("potion 2", 10, 0);
    items[9] = Item("potion 3", 15, 0);
}

// tuple<Item, Item, Item> Chest::generate_chest()
// {
//     auto content = make_tuple(nullptr, nullptr, nullptr);
//     for(int i=0; i<3; i++)
//     {
//         int idx = rand() % 10;
//         get<i>(&items[idx])

//     }
// }

Item Chest::pop_item()
{
    srand(time(0));
    int idx = rand() % 10;
    Item sel_item =  items[idx];
    Item* new_items = new Item[item_number -1];
    int current = 0;
    for(int i=0; i<item_number; i++)
    {
        if(items[i] != items[idx])
        {
            *(new_items + current) = *(items +i);
            current++;
        }
    }
    delete [] items;
    items = new_items;
    return sel_item;

}
