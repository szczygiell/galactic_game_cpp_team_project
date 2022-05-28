#include <iostream>
#include "Gameplay.h"
#include "Player.h"
#include "Enemy.h"

/*
uwagi dotyczace kodu
-czy korzystamy gdzies z bezparametrowego konstruktora enemy

-czy gameplay wgl musi byc klasa xdd nwm czy kozuszek sie o to nie przyczepi
ze obiekt gameplay to wsm nic nie robi, w dokumentacji napisalem ze klasa
zostala stworzona dla czytelnosci kodu

-moze powinnismy ujednolicic wylapywanie invalid inputu w calym programie
bo mamy na pare roznych sposobow to napisane

-jesli chest zawsze ma te same itemy to imo powinnismy dodawanie itemow zrobic juz w
konstruktorze Chesta

*/

//POPRAWIC SHIELDA BO GOWNO DAJE I ZABIERA HP
//ZMODYFIKOWAC ITEMY W SKRZYNCE TAK ABY TEZ ZABIERALY HP , WD itd...

using namespace std;

void disp_border_in_main()
{
    string hash(70, '#');
    cout << '\n' << hash << '\n'<< std::endl;
}


void plot()
{
    srand(time(0));
    int mercy = 0;
    Gameplay game;
    Chest chest = Chest();
    chest.add_items();
    Player player(100, 10, 1);
    cout <<
    "\nYear 2154. Human civiliation is at edge of collapse.\n\
    You have been sent on a special mission to locate the mythical resource\n\
    that will resolve energetic crisis on Earth.\n\
    You begin your journey on highly dangerous planet, PIPR-2.\n\
    Your task is to defeat the enemies guarding the mystery of the resource, which\n\
    we will call ECTS-30\n\n\n\n";
    cin.get();
    cout << "Your landing is spotted by air guards\n"<< endl;
    Enemy air_guard = Enemy("Air guards", 30, 10, 0);
    //game.battle(player, air_guard);
    if (!player.is_alive())
    {
        cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
        return;
    }
    if (rand() % 4 == 0)
    {
        //game.draw_battle(player, 0);
        if (!player.is_alive())
        {
            cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
            return;
        }
    }
    cout << "You find unidentified package... Could it be the ECTS-30???\n\n";
    //game.disp_chest(player, chest);
    cout << "\nYou have been heard by patrol drones!\n\n";
    Enemy drones = Enemy("Patrol drones", 50, 10, 0);
    cin.get();
    //game.battle(player, drones);
    if (!player.is_alive())
    {
        cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
        return;
    }
    cout << "You reached secret research facility...\n";
    cout << "After you get inside, you find a weird old scientist who runs up to you and\n\
    asks you for help in finding his research documents that he has been working on all his life. \n\
    Do you want to help him?"<<endl;
    cout << "\t\t(y/Y) yes " <<endl;
    cout << "\t\t(n/N) no" <<endl;
    string opt;
    bool cond= true;
    while(cond)
    {
        cin >> opt;
        if(opt[0] == 'Y' || opt[0] == 'y')
        {
            cond =false;
            mercy++;
            cout<<"You decided, you were going to help scientist,\n\
            maybe later he could help you find ECTS"<<endl;
            cout<<"The scientist takes you deeper and deeper into the facility."<<endl;
            cout<<"Suddenly, more scientists appear behind you, it turned out that it was a trap"<<endl;
            Enemy scientists = Enemy("Crazy scientists", 40, 15, 0);
            cin.get();
            game.battle(player, scientists);
            if (!player.is_alive())
            {
                cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
                return;
            }
            cout<<"You managed to kill all scientists and went on to the main room of the facility"<<endl;

        }
        else if (opt[0] == 'N' || opt[0] == 'n')
        {
            cout<<"You told scientist that you didn't have time and want on to the main room of the facility"<<endl;
            cond = false;
        }
        else
        {
            cin.fail();
            cout<<"Enter valid value"<<endl;
        }
    }
    cout << "The classified location of ECTS-30 is guarded by highly advanced robot\n\
    which you'll have to defeat. But it won't be so easy...\n\n";
    cin.get();
    Boss robot = Boss("Guarding robot", 10, 10, 0, *(new Item("Blade", 10, 1)));
    //game.boss_battle(player, robot);
    if (!player.is_alive())
    {
        cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
        return;
    }
    cout << "The robot has been defeated and his cold metal body was lying at your feet.\n\
    Unfortunetelly, despite searching whole reasearch facility, you couldn't any ECTS-30 there.\n\
    But you have not given up hope, thanks to your above-average engineering skills, you managed\n\
    to break into the robot's memory and intercept the encrypted message which referred to the large\n\
    ECTS-30 transport to the planet ALIN-ANA. You knew you had to seize this cargo or else mankind would be doomed.\n "<<endl;
    cin.get();

    disp_border_in_main();
    cout<<"\nLoading new location..."<<endl;
    cout<<"\n\nDid you know that on every planet live various kinds of creatures that are vulnerable to diffrent kinds\n\
     of attacks. Try to figure out which attack is most effective, this way fight will be easier.\n\n"<<endl;
    disp_border_in_main();
    cin.get();
    // cout << "\n\n\n"<< endl;
    // Enemy air_guard = Enemy("Air guards", 30, 10, 0);
    //game.battle(player, air_guard);
    // if (!player.is_alive())
    // {
        // cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
        // return;
    // }
    // if (rand() % 4 == 0)
    // {
        //game.draw_battle(player, 0);
        // if (!player.is_alive())
        // {
            // cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
            // return;
        // }
    // }
    // cout << "You find unidentified package... Could it be the ECTS-30???\n\n";
    //game.disp_chest(player, chest);
    // cout << "\nYou have been heard by patrol drones!\n\n";
    // Enemy drones = Enemy("Patrol drones", 50, 10, 0);
    // cin.get();
    //game.battle(player, drones);
    // if (!player.is_alive())
    // {
        // cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
        // return;
    // }
    // cout << "You reached secret research facility...\n";
    // cout << "The classified location of ECTS-30 is guarded by highly advanced robot\n\
    // which you'll have to defeat. But it won't be so easy...\n\n";
    // cin.get();
    // Boss robot = Boss("Guarding robot", 80, 50, 0, *(new Item("Blade", 10, 1)));
    //game.boss_battle(player, robot);
    // if (!player.is_alive())
    // {
        // cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
        // return;
    // }

}

int main()
{
    cout << "Welcome to our game\nWould you like to play it?" << endl;
    cout << "\t\t(y/Y) yes " <<endl;
    cout << "\t\t(n/N) no" <<endl;
    string opt;
    bool cond= true;
    while(cond)
    {
        cin >> opt;
        if(opt[0] == 'Y' || opt[0] == 'y')
        {
            cond =false;
        }
        else if (opt[0] == 'N' || opt[0] == 'n')
        {
            cout<<"See you later"<<endl;
            cond = false;
            exit(0);
        }
        else
        {
            cin.fail();
            cout<<"Enter valid value"<<endl;
        }
    }
    plot();
}
