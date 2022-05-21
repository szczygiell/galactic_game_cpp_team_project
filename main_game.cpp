#include <iostream>
#include "Gameplay.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;











void plot()
{
    //cala fabula
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
        }
        else
        {
            cin.fail();
            cout<<"Enter valid value"<<endl;
        }
    }
}
