#include <iostream>
#pragma once

// akcja w grze + przejscie do nastepnego trybu gry (skrzynia/walka)
class Action
{
    public:
        Action() {}

        int get_choice();
        bool start_game(int& ch);
        bool end_game();
};
