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


void plot()
{
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
    Enemy air_guard = Enemy("Air guards", 30, 5, 0);
    game.battle(player, air_guard);
    game.draw_battle(player, 0);
    cout << "You find unidentified package... Could it be the ECTS-30???\n\n";
    game.disp_chest(player, chest);
    cout << "\nYou have been heard by patrol drones!\n\n";
    Enemy drones = Enemy("Patrol drones", 50, 10, 0);
    cin.get();
    game.battle(player, drones);
    cout << "You reached secret research facility...\n";
    cout << "The classified location of ECTS-30 is guarded by highly advanced robot\n\
    which you'll have to defeat. But it won't be so easy...\n\n";
    cin.get();
    Boss robot = Boss("Guarding robot", 80, 30, 0, *(new Item("Blade", 10, 1)));
    game.boss_battle(player, robot);


    if (!player.is_alive())
        cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;

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
