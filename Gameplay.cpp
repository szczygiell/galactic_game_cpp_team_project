#include <iostream>
#include "Gameplay.h"
#include "Boss.h"
#include "Enemy.h"
#include <limits>
using namespace std;

void disp_border()
{
    string hash(100, '#');
    cout << '\n' << hash << '\n'<< std::endl;
}

void Gameplay::disp_battle(Player& player, Enemy& enemy, int& round)
{
    disp_border();
    cout << "\t\t\t\t\tCurrent stage: " << "\t round: "<< round << endl;  //wpisujemy etap
    cout << "\tOptions:\n";
    cout << "\t\t(1) Attack --> Attack kinds: (0)water (1)fire (2)air (3)earth" << endl;
    cout << "\t\t(2) Defend and regenerate" << endl;
    cout << "\n";
    cout << "\n";
    cout << "\t**Player (You)**" << endl;
    cout << "\tAttack points: " << player.get_wd() << endl; // player.atrybuty
    cout << "\tProtection points: " << player.get_sh() << endl;
    cout << "\tHealth: " << player.get_h() << "/" << player.get_mh() << endl;
    cout << "\n\n\t**Enemy: " << enemy.get_name() << endl;
    cout << "\tEnemy attack points: " << enemy.get_ewd() << endl; // enemy.atrybuty
    cout << "\tEnemy health: " << enemy.get_ehealth() << endl;
    disp_border();
}

void Gameplay::boss_battle(Player &player, Boss &boss)
{
    battle(player, boss);
    Item bitem = boss.get_bitem_info();
    if(!boss.is_alive())
    {
        cout << "You defeated the Boss\nIn return you get ";
        bitem.print();
    }
    cout << "koniec walki" << endl;
    if(bitem.get_ikind() == 0)
        player.heal(bitem.get_ivalue());
    else if(bitem.get_ikind() == 1)
        player.pick_up(bitem.get_ivalue());
    else
        player.set_sh(player.get_sh() + bitem.get_ivalue());
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
            cout<<"choose option: "<<endl;
            cin >> option;
            while(cin.fail())
            {
                cin.clear(); cin.ignore(512, '\n');
                cout << "Invalid Value. Type again... [hint: Input should be a number]\n";
                cin >> option;
            }
            if(option == 1)
            {
                int option2;
                bool cond2=true;
                while(cond2)
                {
                    cout<<"Choose kind of attack"<<endl;
                    cin >> option2;
                    while(cin.fail())
                    {
                        cin.clear(); cin.ignore(512, '\n');
                        cout << "Invalid Value. Type again... [hint: Input should be a number]\n";
                        cin >> option2;
                    }
                    if(option2 == 0||option2 == 1||option2 == 2||option2 == 3)
                    {
                        if(enemy.dodge() == false)
                        {
                            enemy.take_damage(player.attack_kind(enemy, option2));
                            cout<<"You hit enemy for "<<player.attack_kind(enemy, option2)<<endl;
                        }
                        else
                            cout<<"Enemy dodged your attack "<<endl;
                        player.take_damage(enemy.deal_dmg());
                        cout<<"Enemy hit you for "<<enemy.deal_dmg()<<endl;
                        cond2 = false;
                        cond = false;
                    }
                    else
                    {
                        cin.ignore();
                        cout<<"Enter valid value"<<endl;
                        continue;

                    }
                }
            }
            else if(option == 2)
            {
                //obrona i regeneracja
                srand(time(0));
                int chance = rand() % (6 - player.get_sh());
                if(chance == 0)
                {
                    player.heal(10);
                    cout<<"You healed yourself"<<endl;
                }
                else
                {
                    player.take_damage(enemy.deal_dmg());
                    cout<<"Enemy hit you for "<<enemy.deal_dmg()<<endl;
                }
                cond = false;
            }
            else
            {
                cout << "Enter valid value" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        round++;
    }

    if(!player.is_alive())
    {
        cout << "YOU DIED..." << endl;
    }
    if(!enemy.is_alive())
    {
        cout << "YOU WON...\n Congratulations!" << endl;
    }
}

void Gameplay::disp_chest(Player& player, Chest& chest) // jako drugi parametr będzie musiało być: ', Chest& chest'
{
    disp_border();
    string opt;
    Item item = chest.pop_item();
    cout << "\tYou have found a chest. Inside is "<< item.get_iname() <<endl;
    cout << "Do you wnat to pick it up"<<endl;
    cout << "\t\t(y/Y) yes " <<endl;
    cout << "\t\t(n/N) no" <<endl;
    bool cond= true;
    while(cond)
    {
        cin >> opt;
        if(opt[0] == 'Y' || opt[0] == 'y')
        {
            // jest jakiś mały problem ponieważ nawet jesli pokonamy przeciwnika to po
            // podniesieniu itemku (wszystkie wejscia do konsoli poprawne) i po  wyswietleniu
            // np 'item dodal ci tyle hp' to i tak wyswietla sie Enter calid value
            if(item.get_ikind() == 0)
            {
                player.heal(item.get_ivalue());
                cout << '\n' << item.get_iname()<< " healed you for "<<item.get_ivalue()<<endl;
            }
            else if(item.get_ikind() == 1)
            {
                player.pick_up(item.get_ivalue());
                cout << '\n' << item.get_iname()<< " increased your damage by "<<item.get_ivalue()<<" points"<<endl;
            }
            else
            {
                player.set_sh(player.get_sh() + item.get_ivalue());
                cout << '\n' <<item.get_iname()<< " increased your shield by "<<item.get_ivalue()<<" points"<<endl;
            }
            cond =false;
        }
        else if (opt[0] == 'N' || opt[0] == 'n')
        {
            cout<<"You left item"<<endl; //?
            cond = false;
        }
        else
        {
            cin.fail();
            cout<<"Enter valid value"<<endl;
        }
    }
    cout << "\n";
    //cout << "\t\t\t\t\tCurrent stage: " << endl;

    // cout << "\t\t(1) " << "przykladowa zawartosc skrzyni (laser 'A0' [+1 ap])" << endl; // elementy skrzyni po kolei
    // cout << "\t\t(2) " << " przydaloby się zrobic operator<< "<< endl; // zależnie jak stworzymy ostatecznie skrzynie
    // cout << "\t\t(3) " << "mozna by wtedy wyswietlac w miare latwo " <<endl; // to tutaj będzie musiało się to jakoś utworzyć
    // cout << "\n";
    disp_border();
    cout << "Current atributes:\n"<<endl;
    cout << "\t**Player (You)**" << endl;
    cout << "\tAttack points: " << player.get_wd() << endl; // player.atrybuty
    cout << "\tProtection points: " << player.get_sh() << endl;
    cout << "\tHealth: " << player.get_health() << "/" << player.get_mh() << endl;
    cout << "\n";
    disp_border();
}

Enemy generate_enemy(int const& level, int const& ek)
{
    srand(time(0));
    int ehealth = (rand() % (5+ level))*5;
    int ewd = rand() % (5 + level);
    return Enemy(ehealth, ewd, ek);
}

