#include "exercise.h"

using namespace ex9_2;

int main()
{
    std::cout << "Building list A\n";
    Name_Pairs lista = Name_Pairs();
    lista.read_names();
    lista.read_ages();
    //cout << lista;
    lista.sort();
    std::cout << lista;

    std::cout << "Building list B\n";
    Name_Pairs listb = Name_Pairs();
    listb.read_names();
    listb.read_ages();
    //cout << listb;
    listb.sort();
    std::cout << listb;

    if (lista == listb) { std::cout << "are equal\n"; }
    if (lista != listb) { std::cout << "are not equal\n"; }
}