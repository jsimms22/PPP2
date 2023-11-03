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
        int sum = 0;
        for (int i = 0; i < m_roman_numeral.length(); i++) {
            if (roman_to_int_map[m_roman_numeral[i]] < roman_to_int_map[m_roman_numeral[i+1]]) {
                sum -= roman_to_int_map[m_roman_numeral[i]];
            } else {
                sum += roman_to_int_map[m_roman_numeral[i]];
            }
        }
        return sum;
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