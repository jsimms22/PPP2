#include "exercise.h"

using namespace ex9_2;

int main()
{
    cout << "Building list A\n";
    Name_Pairs lista = Name_Pairs();
    lista.read_names();
    for (std::string element : lista.name) {
        std::cout << element << std::endl;
    }

    cout << "Building list B\n";
    Name_Pairs listb = Name_Pairs();
    listb.read_names();
    for (std::string element : listb.name) {
        std::cout << element << std::endl;
    }

    if (lista == listb) { cout << "well I guess it might work\n"; } 
}