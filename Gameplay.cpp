#include <iostream>
#include "Gameplay.h"
using namespace std;

void disp_border()
{
    std::string hash(100, '#');
    std::cout << hash << std::endl;
}

void Gameplay::disp_level(const int& ph, const int& wd, const int& sh,
                                const int& eh, const int& ewd)
{
    disp_border();
    cout << "\n";
    cout << "\t\t\t\t\tCurrent stage: " << endl;;  //wpisujemy etap
    cout << "\tOptions:\n";
    cout << "\t\t(1) " << endl;
    cout << "\t\t(2) " << endl;
    cout << "\t\t(3) " << endl;
    cout << "\n"; 
    cout << "\n";
    cout << "**Player (You)**" << endl;
    cout << "Attack points: " << wd << endl; // player.atrybuty
    cout << "Protection points: " << sh << endl;
    cout << "Health: " << ph <<endl;
    cout << "\n\n**Enemy**" << endl;
    cout << "Enemy attack points: " << ewd << endl; // enemy.atrybuty
    cout << "Enemy health: " << eh << endl;

    disp_border();

}