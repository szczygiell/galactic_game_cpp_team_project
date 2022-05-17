#include <iostream>
#include "Gameplay.h"
#include <tuple>

using namespace std;

void disp_border()
{
    string hash(100, '#');
    cout << hash << std::endl;
}

tuple<int, int, int, int, int, int> Gameplay::get_state(Player& player, Enemy& enemy)
{
    int ph = player.get_h();
    int mh = player.get_mh();
    int wd = player.get_wd();
    int sh = player.get_sh();
    int ewd = enemy.get_ewd();
    int eh = enemy.get_ehealth();
    return make_tuple(wd, sh, ph, mh, ewd, eh);
}

void Gameplay::disp_level(Player& player, Enemy& enemy)
{
    auto params = Gameplay::get_state(player, enemy);
    disp_border();
    cout << "\n";
    cout << "\t\t\t\t\tCurrent stage: " << endl;;  //wpisujemy etap
    cout << "\tOptions:\n";
    cout << "\t\t(1) " << endl;
    cout << "\t\t(2) " << endl;
    cout << "\t\t(3) " << endl;
    cout << "\n";
    cout << "\n";
    cout << "\t**Player (You)**" << endl;
    cout << "\tAttack points: " << get<0>(params) << endl; // player.atrybuty
    cout << "\tProtection points: " << get<1>(params) << endl;
    cout << "\tHealth: " << get<2>(params) << "/" << get<3>(params) << endl;
    cout << "\n\n\t**Enemy**" << endl;
    cout << "\tEnemy attack points: " << get<4>(params) << endl; // enemy.atrybuty
    cout << "\tEnemy health: " << get<5>(params) << endl;
    cout << "\n";
    disp_border();
}

tuple<int, int, int, int> Gameplay::get_state_chest(Player& player)
{
    int ph = player.get_h();
    int mh = player.get_mh();
    int wd = player.get_wd();
    int sh = player.get_sh();
    // jakies informacje do krotki co jest w skrzyni
    return make_tuple(wd, sh, ph, mh);
}

void Gameplay::disp_chest(Player& player) // jako drugi parametr będzie musiało być: ', Chest& chest'
{
    auto params = Gameplay::get_state_chest(player);
    disp_border();
    cout << "\n";
    cout << "\t\t\t\t\tCurrent stage: " << endl;;  //wpisujemy etap
    cout << "\tOptions:\n";
    cout << "\t\t(1) " << "przykładowa zawartość skrzyni (laser 'A0' [+1 ap])" << endl; // elementy skrzyni po kolei
    cout << "\t\t(2) " << " przydałoby się zrobić operator<< "<< endl; // zależnie jak stworzymy ostatecznie skrzynie
    cout << "\t\t(3) " << "można by wtedy wyświetlać w miare latwo " <<endl; // to tutaj będzie musiało się to jakoś utworzyć
    cout << "\n";
    cout << "\n";
    cout << "\t**Player (You)**" << endl;
    cout << "\tAttack points: " << get<0>(params) << endl; // player.atrybuty
    cout << "\tProtection points: " << get<1>(params) << endl;
    cout << "\tHealth: " << get<2>(params) << "/" << get<3>(params) << endl;
    cout << "\n";
    disp_border();
}