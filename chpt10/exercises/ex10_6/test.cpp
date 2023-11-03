#include<iostream>
#include "r_numeral.h"

int main() {
    roman::Roman_Int test1 = roman::Roman_Int{"XVI"};       // 16
    roman::Roman_Int test2 = roman::Roman_Int{"XLV"};       // 45
    roman::Roman_Int test3 = roman::Roman_Int{"LVIII"};     // 58
    roman::Roman_Int test4 = roman::Roman_Int{"III"};       // 3
    roman::Roman_Int test5 = roman::Roman_Int{"MCMXCIV"};   // 1994

    std::cout << "value of " << test1.get_numeral_string() << " : " << test1.as_int() << '\n';
    std::cout << "value of " << test2.get_numeral_string() << " : " << test2.as_int() << '\n';
    std::cout << "value of " << test3.get_numeral_string() << " : " << test3.as_int() << '\n';
    std::cout << "value of " << test4.get_numeral_string() << " : " << test4.as_int() << '\n';
    std::cout << "value of " << test5.get_numeral_string() << " : " << test5.as_int() << '\n';
}