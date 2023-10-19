#include "exercise.h"

using namespace ex9_2;

int main()
{
    Name_Pairs list = Name_Pairs();
    list.read_names();
    for (std::string element : list.name) {
        std::cout << element << std::endl;
    }
}