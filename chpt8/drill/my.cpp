#include "my.hpp"
//#include<iostream>

int foo;    // defining foo
int my::foo;// defining my::foo

void print_foo()
{
    std::cout << foo << '\n';
}

void print(int i)
{
    std::cout << i << '\n';
}

void my::print_foo()
{
    std::cout << my::foo << '\n';
}

void my::print(int i)
{
    std::cout << i << '\n';
}