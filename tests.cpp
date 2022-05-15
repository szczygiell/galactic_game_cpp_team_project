#include <iostream>
#include "Person.h"
#include "Player.h"

using namespace std;

void create_player(int mh, int wd, int sh, int h)
{
    Player *player = new Player(h, mh, wd, sh);
    if (player->get_health() == h && 
        player->get_mh() == mh && player->get_wd() == wd && 
        player->get_sh() == sh)
        cout << "Create player passed" << endl;
    else
        cout << "Error in create player"<< endl;
    
}

void heal_player(const int &potion)
{
    Player *player = new Player(10, 20, 5, 5);
    player->heal(potion);
    if (player->get_health() == 15)
        cout << "Heal player passed" << endl;
    else
        cout << "Error in heal player" << endl;
}

void max_heal_player(const int &potion)
{
    Player *player = new Player(10, 20, 5, 5);
    player->heal(potion);
    if (player->get_health() == 20)
        cout << "Max heal player passed" << endl;
    else
        cout << "Error in max heal player"<< endl;
}

void pick_up_player(int new_wd)
{
    Player *player = new Player(10, 20, 5, 5);
    player->pick_up(new_wd);
    if (player->get_wd() == 10)
        cout << "Pick up player passed" << endl;
    else
        cout << "Error in pick up player"<< endl;
}


int main()
{
    create_player(10, 20, 5, 5);
    heal_player(5);
    max_heal_player(15);
    pick_up_player(5);
    cout << "\n\nEnd of tests" << endl;

}