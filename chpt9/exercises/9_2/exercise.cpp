#include "exercise.h"

namespace ex9_2
{
    void Name_Pairs::read_names()
    {
        std::cout << "provide names below, enter q to quit\n";
        while (std::cin) {
            std::string n;
            std::cin >> n;
            if (n == "q") { break; }

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "bad input, try again\n";
            }
            name.push_back(n);
        }
    }

    void Name_Pairs::read_ages()
    {
        /* TODO */
    }

    void Name_Pairs::sort()
    {

    }
    /*
    std::ostream& operator<<(std::ostream& os, const Name_Pairs a)
    {
        return os;
    }
    */
    /*
    bool operator==(const Name_Pairs a, const Name_Pairs b)
    {
        
    }
    bool operator!=(const Name_Pairs a, const Name_Pairs b)
    {
        return !(a==b);
    }
    */

}