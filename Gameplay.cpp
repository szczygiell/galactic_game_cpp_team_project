#include <iostream>
#include "Gameplay.h"

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

void Gameplay::disp_battle(Player& player, Enemy& enemy, int& round)
{
    auto params = Gameplay::get_state(player, enemy);
    disp_border();
    cout << "\n";
    cout << "\t\t\t\t\tCurrent stage: " << "\t round: "<< round << endl;;  //wpisujemy etap
    cout << "\tOptions:\n";
    cout << "\t\t(1) Attack --> Attack kinds: (0)water (1)fire (2)air (3)earth" << endl;
    cout << "\t\t(2) Defend and regenerate" << endl;
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
    cout << "\t\t(1) " << "przykladowa zawartosc skrzyni (laser 'A0' [+1 ap])" << endl; // elementy skrzyni po kolei
    cout << "\t\t(2) " << " przydaloby się zrobic operator<< "<< endl; // zależnie jak stworzymy ostatecznie skrzynie
    cout << "\t\t(3) " << "mozna by wtedy wyswietlac w miare latwo " <<endl; // to tutaj będzie musiało się to jakoś utworzyć
    cout << "\n";
    cout << "\n";
    cout << "\t**Player (You)**" << endl;
    cout << "\tAttack points: " << get<0>(params) << endl; // player.atrybuty
    cout << "\tProtection points: " << get<1>(params) << endl;
    cout << "\tHealth: " << get<2>(params) << "/" << get<3>(params) << endl;
    cout << "\n";
    disp_border();
}


void Gameplay::battle(Player &player, Enemy &enemy)
{
    disp_border();
    cout << "!!!WATCH OUT FOR ENEMY!!!" << endl;
    cout << "You have been attacked by " << enemy.get_name() << endl;
    cout << "Good luck!" << endl;
    disp_border();
    int round = 0;
    while(player.is_alive() && enemy.is_alive())
    {
        int option;
        disp_battle(player, enemy, round);

        bool cond = true;
        while(cond)
        {
            cin >> option;
            if(option == 1)
            {
                int option2;
                bool cond2=true;
                while(cond2)
                {
                    cout<<"Choose kind of attack"<<endl;
                    cin >> option2;
                    if(option2 == 0||option2 == 1||option2 == 2||option2 == 3)
                    {
                        if(enemy.dodge() == false)
                        {
                            enemy.take_damage(player.attack_kind(enemy, option2));
                        }
                        player.take_damage(enemy.deal_dmg());
                        cond2 = false;
                        cond = false;
                    }
                    else
                    {
                        cout<<"Enter valid value"<<endl;
                        continue;

                    }
                }
            }
            else if(option == 2)
            {
                //obrona i regeneracja
                srand(time(0));
                int chance = rand() % 5;
                if(chance == 0)
                    player.heal(10);
                else
                    player.take_damage(enemy.deal_dmg());
                cond = false;
            }
            else
            {
                cout << "Enter valid value" << endl;
                continue;
            }
        }
        round++;
    }

    if(!player.is_alive())
    {
        cout << "YOU DIED...\n" << endl;
    }
    if(!enemy.is_alive())
    {
        cout << "YOU WON...\n Congratulations!" << endl;
    }

}



