#include <iostream>
#include "Person.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "Chest.h"
#include "Gameplay.h"
#include "Boss.h"


using namespace std;

void create_player(int mh, int wd, int sh, int h)
{
    Player *player = new Player(h, wd, sh);
    if (player->get_health() == h &&
        player->get_mh() == 100 && player->get_wd() == wd &&
        player->get_sh() == sh)
        cout << "Create player passed" << endl;
    else
        cout << "Error in create player"<< endl;
}

void create_enemy(int h, int wd, int ek)
{
    Enemy *enemy = new Enemy("Wrog", h, wd, ek);
    if(enemy->get_ehealth() == h &&
        enemy->get_ewd() == wd && enemy->get_ekind() == ek)
        cout << "Create enemy passed" << endl;
    else cout<< "Error in create enemy" << endl;
}

void heal_player(const int &potion)
{
    Player *player = new Player(10, 5, 5);
    player->heal(potion);
    if (player->get_health() == 15)
        cout << "Heal player passed" << endl;
    else
        cout << "Error in heal player" << endl;
}

void max_heal_player(const int &potion)
{
    Player *player = new Player(10, 5, 5);
    player->heal(potion);
    if (player->get_health() == 20)
        cout << "Max heal player passed" << endl;
    else
        cout << "Error in max heal player"<< endl;
}

void pick_up_player(int new_wd)
{
    Player *player = new Player(10, 5, 5);
    player->pick_up(new_wd);
    if (player->get_wd() == 10)
       cout << "Pick up player passed" << endl;
    else
        cout << "Error in pick up player"<< endl;
}

void create_item(const string n, const int v, const int k)
{
    Item *item = new Item(n, v, k);
    if(item->get_iname() == n &&
        item->get_ivalue() == v && item->get_ikind() == k)
        cout << "Create item passed" << endl;
    else cout<< "Error in create item" << endl;
}

void item_print_test(const string n, const int v, const int k)
{
    Item *item = new Item(n, v, k);
    item->print();
    cout << "Item print test passed" << endl;
}

void test_chest()
{
    Chest skrzyneczka;
    skrzyneczka[5].print();
}

void test_pop_chest()
{
    Chest skrzyneczka;
    for(int i=0; i<10;i++)
        skrzyneczka[i].print();
    cout<<endl;
    Item rm_item = skrzyneczka.pop_item();
    rm_item.print();
    cout<<endl;
    for(int i=0; i<9;i++)
        skrzyneczka[i].print();
}

void test_enemy_take_damage(const int& dmg)
{
    Enemy *enemy = new Enemy("Wrog", 20, 2, 1);
    enemy->take_damage(dmg);
    if(enemy->get_ehealth() == (20-dmg))
        cout << "enemy take_damage passed" << endl;
    else
        cout << "Error in enemy take_damage"<< endl;
}

void test_is_enemy_alive()
{
    Enemy *enemy = new Enemy("Wrog", 20, 2, 1);
    enemy->take_damage(21);
    if(!enemy->is_alive())
        cout << "enemy is_alive passed" << endl;
    else
        cout << "Error in enemy is_alive"<< endl;
}

void create_test_boss(int h, int wd, int ek, Item &si)
{
    Boss szefo = Boss("Boss", h, wd, ek, si);
    if(szefo.get_ehealth() == h && szefo.get_ewd() == wd
    && szefo.get_ekind() == ek && szefo.get_bitem_info() == si)
        cout << "Create boss passed" << endl;
    else cout<< "Error in create boss" << endl;
}

void test_attack_kind()
{
    Enemy enemy = Enemy("Wrog", 20, 2, 1);
    Player player = Player(10, 6, 1);
    int ak1 = 1;
    int ak2 = 2;
    if(player.attack_kind(enemy, ak1) == 9 && player.attack_kind(enemy, ak2) == 6)
        cout<<"attack kind test passed"<<endl;
    else
        cout<<"Error in attack kind test"<<endl;
}

int main()
{
    create_player(10, 20, 5, 5);
    heal_player(5);
    max_heal_player(15);
    pick_up_player(5);
    create_enemy(15, 20, 3);
    create_item("Laser", 10, 1);
    item_print_test("Laser", 10, 1);
    test_chest();
    // Player player(100, 100, 4, 1);
    // Enemy enemy(50, 10, 1);
    // Item * piwo = new Item("Piwo", 10, 1);
    // Boss boss = Boss(10, 20, 2, *piwo);
    // Gameplay game;
    // game.boss_battle(player, boss);
    // Chest chest = Chest();
    // game.disp_chest(player, chest);
    // test_pop_chest();

    test_enemy_take_damage(7);
    test_is_enemy_alive();

    //create_test_boss(10, 2, 4, *piwo);
    test_attack_kind();
    cout << "\nEnd of tests" << endl;

}


//POPRAWIC MECHANIKE WALKI
//NAPISAC OPCJE WYCHODZENIA Z GRY
//POPRAWIĆ NIESKOŃCZONĄ PĘTLE CHOOSE OPTION
//MAIN Z GRĄ
//FABUŁA
//KLASA POZIOM(DO OMÓWIENIA)
