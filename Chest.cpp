#include "Chest.h"
#include <stdlib.h>
#include <iostream>

using namespace std;


Item Chest::pop_item()
{
    int num = get_num();
    srand(time(0));
    int idx = rand() % num;
    Item sel_item =  items[idx];
    int new_num = item_number - 1;
    Item* new_items = new Item[new_num];
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
    item_number--;
    return sel_item;

}
