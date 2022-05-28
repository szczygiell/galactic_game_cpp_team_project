#include <iostream>
#include "Gameplay.h"
#include "Boss.h"
#include "Enemy.h"
#include <limits>
using namespace std;

#include<unistd.h>
const unsigned int microsecond = 500000;
// nie wiem czy to dobry pomysł z globalną zmienną ale na pewno jest to wygodne


void disp_border()
{
    string hash(70, '#');
    cout << '\n' << hash << '\n'<< std::endl;
}

void Gameplay::disp_battle(Player& player, Enemy& enemy, int& round)
{
    disp_border();
    cout << "\t\t\tCurrent stage: " << "\t round: "<< round << endl;
    cout << "\tOptions:\n";
    cout << "\t\t(1) Attack --> Draw special attack from 0 to 3" << endl;
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
    Item bitem = boss.get_bitem_info();
    if(!boss.is_alive())
    {
        cout << "You defeated the Boss\nIn return you get ";
        bitem.print();
    }
    else
        cout << "You were defeated by the boss" << endl;
    if(bitem.get_ikind() == 0)
        player.heal(bitem.get_ivalue());
    else if(bitem.get_ikind() == 1)
        player.pick_up(bitem.get_ivalue());
    else
        player.set_sh(player.get_sh() + bitem.get_ivalue());
}

void Gameplay::battle(Player &player, Enemy &enemy)
{
    cout << "Press any key to continue...\n" << endl;
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
                    if(option2 == 0||option2 == 1||option2 == 2||option2 == 3)
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
        usleep(3 * microsecond);
        cout << "\nYOU DIED...\n\n" << endl;
    }
    if(!enemy.is_alive())
    {
        usleep(3 * microsecond);
        cout << "\nYOU WON...\n Congratulations!\n\n" << endl;
    }
}

void Gameplay::disp_chest(Player& player, Chest& chest)
{
    usleep(3 * microsecond);
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
            usleep(3 * microsecond);
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
    cout << "\n";
    disp_border();
    cout << "Current atributes:\n"<<endl;
    cout << "\t**Player (You)**" << endl;
    cout << "\tAttack points: " << player.get_wd() << endl;
    cout << "\tProtection points: " << player.get_sh() << endl;
    cout << "\tHealth: " << player.get_health() << "/" << player.get_mh() << endl;
    cout << "\n";
    disp_border();
}

std::string draw_rand_name(int const& ek)
{
    srand(time(0));
    int temp = rand() % 3;
    if(ek == 0)
        if(temp = 0)
            return "Pythonian guardian";
        if(temp = 1)
            return "Overflow beast";
        if(temp = 2)
            return "";
    if(ek == 1)
        if(temp = 0)
            return "Integral guards";
        if(temp = 1)
            return "Fouriers nemezis";
        if(temp = 2)
            return "Taylor The Humanoid";
    if(ek == 2)
        if(temp = 0)
            return "Electric eel";
        if(temp = 1)
            return "Evil Shipbuilder";
        if(temp = 2)
            return "";
    if(ek == 3)
        if(temp = 0)
            return "Diabolic Segmentation fault";
        if(temp = 1)
            return "Memorius Referencus";
        if(temp = 2)
            return "";
    else
        return "undefined kind of creature";
}

Enemy generate_enemy(int const& ek)
{
    // problemem z tym że ta walka od razu się kończy jest to że z jakiegoś
    // przypisuje mu 0 zdrowia
    // jeśli usunie się tego ifa z funkcji draw_battle to jest git
    //  trzeba to ogarnąć

    srand(time(0));
    int ehealth = (rand() % (5+ ek))*5;
    int ewd = rand() % (5 + ek);

    Enemy gienek = Enemy(draw_rand_name(ek), ehealth, ewd, ek);

    // cout << "\n\n"<< gienek.get_name() << '\n' << gienek.get_health()
    // << "\t=\t" << gienek.get_ehealth() << '\n' << gienek.get_ewd() << "\n\n" << endl;

    return gienek;
}


void Gameplay::draw_battle(Player &player, int const& ek)
{
    cout << "1 - weszło do funckji" << endl;
    srand(time(0));
    if (rand() % 5 == 0)
    {
        Enemy rand_enemy = generate_enemy(ek);
        cout << "You were unexpectedly attacted by an unknown enemy" << endl;
        battle(player, rand_enemy);
    }if (rand() % 5 == 0)
    {
        Enemy rand_enemy = generate_enemy(ek);
        cout << "You were unexpectedly attacted by an unknown enemy" << endl;
        battle(player, rand_enemy);
    }
}

