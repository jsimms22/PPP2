#include<iostream>
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
            names.push_back(n);
        }
    }

    void Name_Pairs::read_ages()
    {
        std::cout << "Please provide the ages for each person in list\n";
        for (std::string element : Name_Pairs::names) {
            std::cout << "How old is " << element << ": ";
            double temp_age;
            std::cin >> temp_age;
            ages.push_back(temp_age);
        }

        if (ages.size() != names.size()) { error("did not input all of the ages for people."); }
    }

    void Name_Pairs::sort()
    {
        if (names.size() != ages.size()) { error("unable to sort name-age pairs with nonequal length name and age lists"); }

        for (int i = 0; i < names.size(); i++) {
            for (int j = 0; j < names.size(); j++) {
                if (i != j) { 
                    if (names[i] < names[j]) { 
                        std::swap(names[i], names[j]);
                        std::swap(ages[i],ages[j]);
                    } 
                }
            }
        }

    }
    
    std::ostream& operator<<(std::ostream& os, const Name_Pairs& a)
    {
        if (a.get_names().size() != a.get_ages().size()) { error("failure to print, list of ages and names are not the same length\n"); }
        for (int i = 0; i < a.get_names().size(); i++) {
            std::cout << a.get_names()[i] << '\t' << a.get_ages()[i] << '\n';
        }
        return os;
    }
    
    bool operator==(const Name_Pairs& a, const Name_Pairs& b)
    {
        bool outcome = true;
        if (a.get_names().size() == b.get_names().size() && a.get_ages().size() == b.get_ages().size()) {
            for (int i = 0; i < a.get_names().size() && outcome == true; i++) {
                if (a.get_names()[i] != b.get_names()[i]) { outcome = false; }
            }
            
            for (int i = 0; i < a.get_ages().size() && outcome == true; i++) {
                if (a.get_ages()[i] != b.get_ages()[i]) { outcome = false; }
            }
        }
        
        return outcome;
    }

    bool operator!=(const Name_Pairs& a, const Name_Pairs& b)
    {
        return !(a==b);
    }
}