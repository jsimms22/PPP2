#include<iostream>
#include<unordered_map>
#include "r_numeral.h"

namespace roman
{

    std::unordered_map<char, int> roman_to_int_map =
    {
        {'I',1}, {'V',5}, {'X',10}, {'L',50}, 
        {'C',100}, {'D',500}, {'M',1000}
    };

    int Roman_Int::as_int()
    {
        int val = 0;
        for (char element : m_roman_numeral) {
            val += roman_to_int_map[element];
        }
        return val;
    }

    std::ostream& operator<<(std::ostream& os, Roman_Int& r) 
    { 
        std::cout << r.get_numeral_string();
        return os;
    }

    std::istream& operator>>(std::istream& is, Roman_Int& r) 
    {
        std::string temp;
        std::cin >> temp;
        r.set_numeral_string(temp);

        return is;
    }
} // namespace roman