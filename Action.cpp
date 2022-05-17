#include <iostream>
#include <stdio.h>
#include "Action.h"

using namespace std;

int Action::get_choice()
{
    int ch;
    ch = getchar();
    return ch;
}

// JAK PRZEKAZAC C PRZEZ REFERENCJE??? NIE TWORZY KOPII
bool Action::start_game(int& ch)
{
    // cout << "Wanna play a game?[y/n]";
    int c = get_choice();
    if(c == int('y'));
}
