#include <iostream>
#include "Gameplay.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;







void plot()
{
    Gameplay game;
    Player player(100, 100, 10, 1);
    cout << "Rok 2154. cywilizacja ziemska jest na skraju upadku. zostales wyslany\
    na specjalna misje odnalezienia mitycznego surowca ktory rozwiaze problem energetyczny\
    na Ziemii. znajdujesz sie na planecie pipr. to bardzo bardzo niebezpieczna planeta.\
    twoim zadaniem jest pokonanie cywilizacji strzezacej tego surowca. ";
    cout << "twoje ladowanie odnotowuja straznicy przestrzeni powietrznej";
    Enemy air_guard = generate_enemy(1, 3);
    game.battle(player, air_guard);

    
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
            //exit
        }
        else
        {
            cin.fail();
            cout<<"Enter valid value"<<endl;
        }
    }
    plot();
}
