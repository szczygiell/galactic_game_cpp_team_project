#include <iostream>
#include "Player.h"
#include "Enemy.h"


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
void Player::pick_up(const int& new_wd)
{
    set_wd(this->weapon_damage + new_wd);
}
void Player::heal(const int &potion)
{
    if (get_health() + potion >= max_health)
        set_health(max_health);
    else
        {
            const int &new_health = get_health() + potion;
            set_health(new_health);
        }
}

int Player::attack_kind(Enemy& enemy, const int& akind)
{
    if(akind == enemy.get_ekind())
        return this->weapon_damage + 0.5 * this->weapon_damage;
    return this->weapon_damage;
}
