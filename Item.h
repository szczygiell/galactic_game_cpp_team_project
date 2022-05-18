#include <iostream>
#pragma once

class Item
{
    private:
        std::string iname;
        int ivalue;
        int ikind;
        // which value represents which kind:
        // 0: health
        // 1: weapon_damage
        // 2: shield
    public:
        Item(){}
        Item(const std::string n, const int v, const int k)
        {
            iname = n;
            ivalue = v;
            ikind = k;
        }

        std::string get_iname() {return iname;};
        int get_ivalue() {return ivalue;};
        int get_ikind() {return ikind;};

        void print()
        {
            std::cout << "(" << iname << ", " << ivalue << ")" << std::endl;
        }

        bool operator==(Item const& item2) const
        {
            return (this->iname == item2.iname);
        }

        bool operator!=(Item const& item2) const
        {
            return  !operator==(item2);
        }
};