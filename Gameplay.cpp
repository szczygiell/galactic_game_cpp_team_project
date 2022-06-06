#include <iostream>
#include "Gameplay.h"
#include "Boss.h"
#include "Enemy.h"
#include <limits>
using namespace std;

#include<unistd.h>

const unsigned int microsecond = 500000;

void disp_border()
{
    string hash(70, '#');
    cout << '\n' << hash << '\n'<< std::endl;
}

void disp_atributes(Player& player)
{
    disp_border();
    cout << "Current atributes:\n"<<endl;
    cout << "\t**Player (You)**" << endl;
    cout << "\tAttack points: " << player.get_wd() << endl;
    cout << "\tProtection points: " << player.get_sh() << endl;
    cout << "\tHealth: " << player.get_health() << "/" << player.get_mh() << endl;
    cout << "\n";
    disp_border();
}

void Gameplay::disp_battle(const Player& player, const Enemy& enemy, const int& round) const
{
    disp_border();
    cout << "\t\t\tCurrent stage: " << "\t round: "<< round << endl;
    cout << "\tOptions:\n";
    cout << "\t\t(1) Attack --> Draw special attack from 1 to 4" << endl;
    cout << "\t\t(2) Defend and regenerate" << endl;
    cout << "\n";
    cout << "\n";
    cout << "\t**Player (You)**" << endl;
    cout << "\tAttack points: " << player.get_wd() << endl;
    cout << "\tProtection points: " << player.get_sh() << endl;
    cout << "\tHealth: " << player.get_h() << "/" << player.get_mh() << endl;
    cout << "\n\n\t**Enemy: " << enemy.get_name() << "**" << endl;
    cout << "\tEnemy attack points: " << enemy.get_ewd() << endl;
    cout << "\tEnemy health: " << enemy.get_ehealth() << endl;
    disp_border();
}

void Gameplay::boss_battle(Player &player, Boss &boss)
{
    battle(player, boss);
    usleep(2 * microsecond);
    Item bitem = boss.get_bitem_info();
    if(!boss.is_alive())
    {
        if(bitem.get_ikind() == 0)
            player.heal(bitem.get_ivalue());
        else if(bitem.get_ikind() == 1)
            player.pick_up(bitem.get_ivalue());
        else
            player.set_sh(player.get_sh() + bitem.get_ivalue());
        cout << "You defeated the Boss\nIn return you get ";
        bitem.print();
        disp_atributes(player);
    }
    else
        cout << "You were defeated by the boss" << endl;

    usleep(4 * microsecond);
}

void Gameplay::battle(Player &player, Enemy &enemy)
{
    cout << "Press 'ENTER' key to continue...\n" << endl;
    cin.get();
    disp_border();
    cout << "!!!WATCH OUT FOR ENEMY!!!" << endl;
    cout << "You have been attacked by " << enemy.get_name() << endl;
    cout << "Good luck!" << endl;
    disp_border();
    int round = 0;
    while(player.is_alive() && enemy.is_alive())
    {
        int option;
        usleep(2 * microsecond);
        disp_battle(player, enemy, round);
        bool cond = true;
        while(cond)
        {
            cout<<"Choose option: "<<endl;
            cin >> option;
            while(cin.fail())
            {
                cin.clear(); cin.ignore(512, '\n');
                cout << "Invalid Value. Type again... [hint: Input should be a number]\n"
                << "if you want to exit press '^C' "<< endl;
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
                    if(option2 == 1||option2 == 2||option2 == 3||option2 == 4)
                    {
                        usleep(3 * microsecond);
                        if(enemy.dodge() == false)
                        {
                            enemy.take_damage(player.attack_kind(enemy, option2));

                            cout<<"\nYou hit enemy for "<<player.attack_kind(enemy, option2)<<endl;
                        }
                        else
                            cout<<"\nEnemy dodged your attack "<<endl;
                        if(enemy.is_alive())
                        {
                            player.take_damage(enemy.deal_dmg());

                            cout<<"\nEnemy hit you for "<<enemy.deal_dmg()<<endl;
                        }
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
                usleep(3 * microsecond);
                srand(time(0));
                int chance = rand() % (100 + player.get_sh());
                if(chance > 60)
                {
                    player.heal(50);

                    cout<<"You healed yourself"<<endl;
                }
                else
                {
                    int damage = enemy.deal_dmg() * 0.5;
                    player.take_damage(damage);
                    cout<<"Enemy hit you for "<<damage<<endl;
                }
                cond = false;
            }
            else
            {
                cout << "\nEnter valid value!\n" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        round++;
    }

    if(!player.is_alive())
    {
        usleep(3 * microsecond);
        cout << "\nYOU DIED...\n\n" << endl;
    }
    if(!enemy.is_alive())
    {
        usleep(3 * microsecond);
        cout << "\nYOU WON...\nCongratulations!\n\n" << endl;
    }
}

void Gameplay::disp_chest(Player& player, Chest& chest)
{
    usleep(3 * microsecond);
    disp_border();
    string opt;
    Item item = chest.pop_item();
    cout << "\tYou have found a chest. Inside is "<< item.get_iname() <<endl;
    cout << "\tDo you wnat to pick it up"<<endl;
    cout << "\t\t(y/Y) yes " <<endl;
    cout << "\t\t(n/N) no" <<endl;
    bool cond= true;
    while(cond)
    {
        cin >> opt;
        if(opt[0] == 'Y' || opt[0] == 'y')
        {
            usleep(3 * microsecond);
            if(item.get_ikind() == 0)
            {
                player.heal(item.get_ivalue());
                cout << '\n' << item.get_iname()<< " healed you for "<<item.get_ivalue()<<endl;
            }
            else if(item.get_ikind() == 1)
            {
                if(item.get_ivalue() >= 0)
                    cout << '\n' << item.get_iname()<< " increased your damage by "<<item.get_ivalue()<<" points"<<endl;
                else
                    cout << '\n' << item.get_iname()<< " damaged you for "<<abs(item.get_ivalue())<<" points"<<endl;
                player.heal(item.get_ivalue());
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
            usleep(3 * microsecond);
            cout<<"You left item"<<endl;
            cond = false;
        }
        else
        {
            cin.fail();
            cout<<"Enter valid value"<<endl;
        }
    }
    usleep(3 * microsecond);
    disp_atributes(player);
}

std::string draw_rand_name(int const& ek)
{
    srand(time(0));
    int temp = rand() % 3;
    cout<<temp<<endl;
    if(ek == 0)
        if(temp == 0)
            return "Pythonian guardian";
        if(temp == 1)
            return "Overflow beast";
        if(temp == 2)
            return "Dynamic memory allocation";
    if(ek == 1)
        if(temp == 0)
            return "Integral guards";
        if(temp == 1)
            return "Fouriers nemezis";
        if(temp == 2)
            return "Taylor The Humanoid";
    if(ek == 2)
        if(temp == 0)
            return "Low-Pass droid";
        if(temp == 1)
            return "Evil Souther world scheme";
        if(temp == 2)
            return "Flail constructor+";
    if(ek == 3)
        if(temp == 0)
            return "Segmentation Fault";
        if(temp == 1)
            return "Dynamic memory allocation";
        if(temp == 2)
            return "Interplanetary Const";
    else
        return "undefined kind of creature";
}

Enemy generate_enemy(int const& ek)
{
    srand(time(0));
    int ehealth = (rand() % (5+ ek))*5 + 10;
    int ewd = rand() % (5 + ek) + 7;
    Enemy rand_enemy = Enemy(draw_rand_name(ek), ehealth, ewd, ek);
    return rand_enemy;
}


void Gameplay::draw_battle(Player &player, int const& ek)
{
    Enemy rand_enemy = generate_enemy(ek);
    cout << "You were unexpectedly attacted by an unknown enemy" << endl;
    battle(player, rand_enemy);
}

