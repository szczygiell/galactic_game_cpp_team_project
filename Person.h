#include <iostream>
#pragma once

class Person
{
    protected:
        int health;

   public:
        Person(int h)
        {
            health = h;
        }
        ~Person();
        virtual int reduce_health(int &damage)
        {
            return this->health-damage;
        }
        virtual int get_health()
        {
            return this->health;
        }
        virtual void set_health(const int &new_health)
        {
            health = new_health;
        }
};
