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


// Planet 1:

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
    // game.battle(player, air_guard);
    if (!player.is_alive())
    {
        cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
        return;
    }
    if (rand() % 4 == 0)
    {
        // game.draw_battle(player, 0);
        if (!player.is_alive())
        {
            cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
            return;
        }
    }
    cout << "You find unidentified package... Could it be the ECTS-30???\n\n";
    game.disp_chest(player, chest);
    cout << "\nYou have been heard by patrol drones!\n\n";
    Enemy drones = Enemy("Patrol drones", 50, 10, 0);
    cin.get();
    // game.battle(player, drones);
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
            // game.battle(player, scientists);
            if (!player.is_alive())
            {
                cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
                return;
            }
            cout<<"You managed to kill all scientists and went on to the main room of the facility"<<endl;

        }
        else if (opt[0] == 'N' || opt[0] == 'n')
        {
            cout<<"You told scientist that you didn't have time and went on to the main room of the facility\n"<<endl;
            cond = false;
        }
        else
        {
            cin.fail();
            cout<<"Enter valid value"<<endl;
        }
    }
cout << "\nThe classified location of ECTS-30 is guarded by highly advanced robot\n\
which you'll have to defeat. But it won't be so easy...\n\n";
    cin.get();
    Boss robot = Boss("Guarding robot", 10, 10, 0, *(new Item("Binary Blade", 10, 1)));
    // game.boss_battle(player, robot);
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
cout<<"\n\nHint:\nDid you know that on every planet live various kinds of creatures that are vulnerable to diffrent kinds\n\
of attacks. Try to figure out which attack is most effective, this way fight will be easier.\n\n"<<endl;
    disp_border_in_main();
    cout << "Press ENTER to continue... " << endl;
    cin.get();
    cout << "\n\n\n"<< endl;


// Planet 2:

    cout << "Just after your take-off from Pipr-2 you came across new problems. The Great PROI nebula\n\
absorbed energy of your ship. You had to stop and recharge the system at the dwarf planet 011B. While you were\n\
waiting to continue the mission you spotted another machine way off in the distance. You thought there\n\
could be an opportunity to get some energy resources.\n\
You decided to come closer but also stay hidden and see what's going on there. You spotted that these machines belongs to the\n\
galactic traders. You peeked out from the rocks and spoke to the traders. After asking for some energy batteries\n\
they refuse to help you." << endl;
    cout << "Do you want to kill them and take their resources?"<<endl;
    cout << "\t\t(y/Y) yes " <<endl;
    cout << "\t\t(n/N) no" <<endl;
    string opt10;
    bool cond10= true;
    while(cond10)
    {
        cin >> opt10;
        if(opt10[0] == 'Y' || opt10[0] == 'y')
        {
            cond10 =false;
            cout << "\nYou told them that you really need their parts and if they don't give you them you will take it by force." << endl;
            cout<<"The galactic traders were not scared of you and engaged in combat!\n"<<endl;
            Enemy traders = Enemy("Galactic traders", 40, 15, 1);
            cin.get();
            // game.battle(player, traders);
            if (!player.is_alive())
            {
                cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
                return;
            }
cout<<"You managed to kill all of the traders and take the resources that you need for your jurney\n\
and came back to your ship.\n"<<endl;
            // można by tu dodać jeszcze opcję ze skrzynią np?
        }
        else if (opt10[0] == 'N' || opt10[0] == 'n')
        {
            mercy++;
            cout<<"You decided that the risk of fighting these aliensis  is too high and came back to your ship.\n"<<endl;
            cond10 = false;
        }
        else
        {
            cin.fail();
            cout<<"Enter valid value"<<endl;
        }
    }
    cout<<
"You have finally arrived at the ALIN-ANA. During your way you got an information about the train transport that\n\
probably contains ECTS-30 resources. You land behind the hill nearby the magnetic railway and started planning the heist.\n\
After spending some time at the peak of the hill you finally spotted the aproaching transport convoy. You waited for\n\
the proper occasion and intruded into imperceptibly.\n\n\n" << endl;
    cin.get();
    cout << "Then the Algebra guard spotted you!" << endl;
    Enemy algebra_guard = Enemy("Algebra guard", 40, 15, 1);
    // game.battle(player, algebra_guard);
    if (!player.is_alive())
    {
        cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
        return;
    }
    if (rand() % 4 == 0)
    {
        cout << "You have heard some strange noises. Your plan didn't predict anything here!\n" << endl;
        // game.draw_battle(player, 1);
        if (!player.is_alive())
        {
            cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
            return;
        }
    }
    cout << "You get into the armory. Maybe there is something interesting?\n\n";
    game.disp_chest(player, chest);
    cout << "\nOops! You entered the wrong area! The Calculus turrets are aimed at you!\n\n";
    Enemy turrets = Enemy("Calculus turrets", 30, 30, 1);
    cin.get();
    // game.battle(player, turrets);
    if (!player.is_alive())
    {
        cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
        return;
    }
cout << "You reached the main carriage. According to the Pipr-2 robot there should be your goal\n\
but you know it would be tough fight. Just as you slammed into the room the Hyperdimmentional Matrix\n\
had activated to defend the ECTS-30 container! ";
    cin.get();
    Boss matrix = Boss("Hyperdimmentional Matrix", 10, 50, 0, *(new Item("Banach–Tarski paradox proof", 20, 1)));
    // game.boss_battle(player, matrix);
    if (!player.is_alive())
    {
        cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
        return;
    }
cout <<
"\nThe Hyperdimmentional matrix break up into millions of prime and numbers. You opened the container and found nothing.\n\
During the fight with the Guardian you didn't realised that some of complex intigers had taken the ECTS-30.\n\
When you found out that the Engine carriege had gone far far away, you spotted some dim light covered by residues\n\
of Matrix elements. You have dig down to the source of that light and you discovered that your enemies have left\n\
very minor part of ECTS-30. This quantity will not even provide the energy supply for your ship, but lckily will\n\
will help you found another parts of your main target.\n\n" << endl;

disp_border_in_main();
    cout<<"\nLoading new location..."<<endl;
cout<<"\n\nHint:\nAll of your actions have a huge impact on the surrounding world\n\n"<<endl;
    disp_border_in_main();
    cout << "Press ENTER to continue... " << endl;
    cin.get();
    cout << "\n\n\n"<< endl;

// Planeta 3:


}

int main()
{
    cout << "! if you want to stop the program press '^C' !\n" << endl;
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
    //  może zrobić plota jako inta który zwraca mercy
    //  i wtedy zaelżnie od wartości mercy oraz przejscia gry
    //  wylosujemy odpowiednie zlaiczenie
    cout << "Hopefully the whole jurney and achived ECTS-30 will help you graduating from ELKA :)"<<endl;
}
