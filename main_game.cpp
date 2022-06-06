#include <iostream>
#include "Gameplay.h"
#include "Player.h"
#include "Enemy.h"


using namespace std;



bool is_done(Player& player)
{
    if (!player.is_alive())
    {
        cout << "\n\nYou, Earht's last hope, didn't manage to save the planet... The era of man has come to an end." << endl;
        return true;
    }
    return false;
}


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
    Enemy* air_guard = new Enemy("Air guards", 30, 10, 1);
    game.battle(player, *air_guard);
    if (is_done(player))
        return;
    delete air_guard;

    if (rand() % 4 == 0)
    {
        game.draw_battle(player, 0);
        if (is_done(player))
        return;

    }
    cout << "You find unidentified package... Could it be the ECTS-30???\n\n";
    game.disp_chest(player, chest);
    if (is_done(player))
        return;
    cout << "\nYou have been heard by patrol drones!\n\n";
    Enemy* drones = new Enemy("Patrol drones", 50, 10, 1);
    cin.get();
    game.battle(player, *drones);
    if (is_done(player))
        return;
    delete drones;

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
            Enemy* scientists = new Enemy("Crazy scientists", 40, 15, 1);
            cin.get();
            game.battle(player, *scientists);
            if (is_done(player))
                return;
            delete scientists;

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
    Boss* robot = new Boss("Guarding robot", 50, 15, 1, *(new Item("Binary Blade", 10, 1)));
    game.boss_battle(player, *robot);
    if (is_done(player))
        return;
    delete robot;

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

    cout << "Just after your take-off from PIPR-2 you came across new problems. The Great PROI nebula\n\
absorbed energy of your ship. You had to stop and recharge the system at the dwarf planet 011B. While you were\n\
waiting to continue the mission you spotted another vehicle way off in the distance.\n\
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
            Enemy* traders = new Enemy("Galactic traders", 40, 15, 2);
            cin.get();
            game.battle(player, *traders);
            if (is_done(player))
                return;
            delete traders;

cout<<"You managed to kill all of the traders and take the resources that you need for your jurney.\n"<<endl;
        }
        else if (opt10[0] == 'N' || opt10[0] == 'n')
        {
            mercy++;
            cout<<"You decided that the risk of fighting these aliensis is too high and came back to your ship.\n"<<endl;
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
the proper occasion to imperceptibly intrude into it.\n\n\n" << endl;
    cin.get();
    cout << "The Algebra guard spotted you!" << endl;
    Enemy* algebra_guard = new Enemy("Algebra guard", 40, 15, 2);
    game.battle(player, *algebra_guard);
    if (is_done(player))
        return;
    delete algebra_guard;

    if (rand() % 4 == 0)
    {
        cout << "You have heard some strange noises! An unexpected enemy?!\n" << endl;
        game.draw_battle(player, 1);
        if (is_done(player))
            return;

    }
    cout << "You get into the armory. Maybe there is something interesting?\n\n";
    game.disp_chest(player, chest);
    if (is_done(player))
        return;
    cout << "\nOops! You entered the wrong area! The Calculus turrets are aimed at you!\n\n";
    Enemy* turrets = new Enemy("Calculus turrets", 30, 30, 2);
    cin.get();
    game.battle(player, *turrets);
    if (is_done(player))
        return;
    delete turrets;

cout << "You reached the main carriage. According to the Pipr-2 robot there should be your search target.\n\
Just as you slammed the hatch, the room turns into the Hyperdimmentional Matrix,\n\
which secures ECTS-30! ";
    cin.get();
    Boss* matrix = new Boss("Hyperdimmentional Matrix", 70, 24, 2, *(new Item("Banach–Tarski paradox proof", 20, 1)));
    game.boss_battle(player, *matrix);
    if (is_done(player))
        return;
    delete matrix;

cout <<
"\nThe Hyperdimmentional matrix broke up into millions of prime and complex numbers. You open the container and found nothing.\n\
During the fight with the Guardian you didn't realise that some of complex integers had taken the ECTS-30.\n\
As the Engine carriage was fading away, you spotted some dim light covered by residues\n\
of Matrix elements. You have dig down to the source of that light and you discovered that your enemies have left\n\
just a fraction of ECTS-30. This quantity will not even provide the energy supply for your ship, but luckily\n\
will help you found another parts of your main target.\n\n" << endl;

disp_border_in_main();
    cout<<"\nLoading new location..."<<endl;
cout<<"\n\nHint:\nAll of your actions have a huge impact on the surrounding world\n\n"<<endl;
    disp_border_in_main();
    cout << "Press ENTER to continue... " << endl;
    cin.get();
    cout << "\n\n\n"<< endl;

// Planeta 3:

cout <<"With small particle of ECTS-30 you decided to contact the best expert on ECTS, Professor Little Coat.\n\
After long journey you finally arrived at PROI-25, planet where professor had his lab. \n\
Unfortunately, you did not find the professor at his place, the whole laboratory was broken\n\
and you could see at first glance that there was a fight here. After searching for a while,\n\
you found a card left by former corrupt students who kidnapped the scientist and want\n\
to take revenge on him for the wasted years at the university.\n\
Without hesitating, you followed the kidnappers\n\n"<<endl;
    cout << "Press ENTER to continue... " << endl;
    cin.get();
    if (rand() % 4 == 0)
    {
        cout<<"You hear starnge sound. Be careful! You have been unexpectedly attacked!"<<endl;
        game.draw_battle(player, 3);
        if (is_done(player))
        return;

    }
cout<<"tracking down students was not difficult thanks to their distinctive smell\n\
and after a while you managed to reach their hideout. You jump in, but the terrified kidnappers don't defend themselves,\n\
they just offer you a deal. If you guess their riddle, you will disperse without a fight, and if you guess wrong,\n\
you will have to fight them."<<endl;

    cout << "Do you want to hear the riddle?"<<endl;
    cout << "\t\t(y/Y) yes " <<endl;
    cout << "\t\t(n/N) no" <<endl;
    string opt2;
    bool cond2= true;
    while(cond2)
    {
        cin >> opt2;
        if(opt2[0] == 'Y' || opt2[0] == 'y')
        {
            mercy++;
            cond2 =false;
            string ans;
            cout << "\nZAGADKA!" << endl;
            cout << "\nW 2016 roku pan Jakub zapytany o rok swoich urodzin odpowiedział:\n\
<<Jeżeli mój wiek z przed 36 lat pomnożysz przez mój wiek za 55 lat to otrzymasz moją datę urodzin.\n\
W którym roku się urodziłem?>>\n\n" << endl;
            cout << "1. 1958 \n2. 1962 \n3. 1970 \n4. 1998"<<endl;
            cout << "Choose correct answear"<<endl;
            cin >> ans;
            if(ans[0] == '2')
                cout<<"You guessed correctly. You leave the hiding place with the professor and go to his laboratory"<<endl;
            else if(ans[0] == '1' || ans[0] == '3' || ans[0] == '4')
            {
                cout<<"Unfortunately you guessed wrong and kidnappers attack you."<<endl;
                Enemy* studnappers = new Enemy("Studnappers", 50, 15, 4);
                cin.get();
                game.battle(player, *studnappers);
                if (is_done(player))
                    return;
                delete drones;
            }
            else
            {
                cout<<"You talked nonsense and noone understood you, so kidnappers attack you."<<endl;
                Enemy* studnappers = new Enemy("Studnappers", 50, 15, 4);
                cin.get();
                game.battle(player, *studnappers);
                if (is_done(player))
                    return;
                delete drones;
            }

        }
        else if (opt2[0] == 'N' || opt2[0] == 'n')
        {
            cout<<"\nYou found something suspicious about this proposal and attacked the kidnappers.\n"<<endl;
            Enemy* studnappers = new Enemy("Studnappers", 50, 15, 4);
            cin.get();
            game.battle(player, *studnappers);
            if (is_done(player))
                return;
            delete drones;
            cond2 = false;
        }
        else
        {
            cin.fail();
            cout<<"Enter valid value"<<endl;
        }
    }
cout << "Back in the lab, the professor took a small ECTS sample from you and tested it.\n\
Thanks to this, he was able to determine where the largest deposits of this material are located in the area.\n\
One was not far away, unfortunately it was very well guarded. You decided there was no time to waste and set out to save humanity"<<endl;
    cout << "Press ENTER to continue... " << endl;
    cin.get();

cout<<"You've reached your destination, but trouble has started here,\n\
well-armed bodyguards are standing at the entrance"<<endl;
    Enemy* body_guards = new Enemy("Fearless body-guards", 60, 17, 4);
    cin.get();
    game.battle(player, *body_guards);
    if (is_done(player))
        return;
    delete body_guards;

    cout << "As you go deeper and deeper into the complex, you find 2 chests.\n\n";
    game.disp_chest(player, chest);
    if (is_done(player))
        return;
    game.disp_chest(player, chest);
    if (is_done(player))
        return;

cout << "\nyou've finally reached the end of your journey.\n\
There is one last obstacle in the way of your success. ENGINEERING THESIS.\n\
You enter a room without knowing if you will leave it alive"<<endl;
    cin.get();
    if(mercy == 3)
    {
cout<<"Thanks to your nobility, the thesis handed ECTS-30 without a fight\n\
sand you managed to save humanity"<<endl;
        return;
    }
    else
    {
        string ans2;
cout << "\nRozważmy następujący fragment kodu:\n\nstruct Klasa:\n{\n\tint a;\npublic:\n\tint b;\n\
private:\n\tint c;\n};\nKtóre z pól klasy Klasa są widoczne prywatnie?\n\nWybierz jedną odpowiedź:\n\n\
1) a i c\n2) tylko c\n3)tylko a\n4) b i c\n"<< endl;
        cout << "1. odp 1 \n2. odp 2 \n3. odp 3 \n4. odp 4"<<endl;
        cout << "Choose correct answear"<<endl;
        cin >> ans2;
        if(ans2[0] == '2')
        {
cout<<"Engineering thesis is surprised by your correct answer, you are very well prepared\n\
and the thesis attacks with much less force than normal."<<endl;
            cin.get();
            Boss* thesis = new Boss("Engineering thesis", 100, 20, 4, *(new Item("ECTS-30", 30, 1)));
            game.boss_battle(player, *thesis);
            if (is_done(player))
                return;
            delete thesis;
        }
        else if(ans2[0] == '1' || ans2[0] == '3' || ans2[0] == '4')
        {
cout<<"Unfortunately, your answer is wrong, the thesis attacks with all its might,\n\
your lack of preparation can destroy you"<<endl;
            cin.get();
            Boss* thesis = new Boss("Engineering thesis", 120, 25, 4, *(new Item("ECTS-30", 30, 1)));
            game.boss_battle(player, *thesis);
            if (is_done(player))
                return;
            delete thesis;
        }
        else
        {
cout<<"You talked nonsense and the thesis attacks with all its might,\n\
your lack of preparation can destroy you"<<endl;
            cin.get();
            Boss* thesis = new Boss("Engineering thesis", 120, 20, 4, *(new Item("ECTS-30", 30, 1)));
            game.boss_battle(player, *thesis);
            if (is_done(player))
                return;
            delete thesis;
        }
    }
    cout<<"You saved humanity and solved energy problem on Earth"<<endl;
}

int main()
{
    disp_border_in_main();
    cout<<"\n\t\t\tAMF STUDIO\n\t\t\t presents\n\t\t'The Finale Exam of Humanity'\n"<<endl;
    disp_border_in_main();
    cout << "\n! if you want to stop the program press '^C' !" << endl;
    cout << "\n\nPress ENTER to continue...\n" << endl;
    cin.get();
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
    cout << "Hopefully the whole jurney and achived ECTS-30 will help you graduating from ELKA :)\n"<<endl;
    cout<<"\n\nThank you for playing our game. We hope you enjoyed it.\n" << endl;
    cout <<"Game made by:\nAdam Rybojad,\nFilip Szczygielski,\nMikołaj Wewiór.\n\n"<<endl;
}
