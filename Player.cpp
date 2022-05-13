#include <iostream>
#include "Player.h"

void Player::set_mh(int mh)
{
    if (mh < 0)
    {
        throw out_of_range("Incorrect max health");
    }
    Player::max_health = mh;
}
void Player::set_wd(int wd)
{
    if (wd < 0)
    {
        throw out_of_range("Incorrect weapon damage");
    }
    weapon_damage = wd;
}
void Player::set_sh(int sh)
{
    if (sh < 0)
    {
        throw out_of_range("Incorrect shield parameter");
    }
    shield = sh;
}
void Player::pick_up(int &new_wd)
{
    Player::weapon_damage += new_wd;
}
void Player::heal(const int &potion)
{
    if (health + potion >= max_health)
        set_health(max_health);
    else
        {
            const int &new_health = health + potion;
            set_health(new_health);
        }
}
