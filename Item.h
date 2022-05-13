#include <iostream>

class Item
{
    private:
        std::string name;
        int value;
        int kind;
        // which value represents which kind:
        // 0: health
        // 1: weapon_damage
        // 2: shield
    public:
        Item(const std::string n, const int v, const int k)
        {
            name = n;
            value = v;
            kind = k;
        }

        std::string get_name() {return name;};
        int get_value() {return value;};
        int get_kind() {return kind;};

        void print()
        {
            std::cout << "(" << name << ", " << value << ")" << std::endl;
        }


        


        
};