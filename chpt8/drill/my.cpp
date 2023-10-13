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

void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_r(double& a, double& b)
{
    int temp = a;
    a = b;
    b = temp;
}

/*
void swap_cr(const int& a, const int& b)
{
    const int& temp = a;
    a = b;
    b = temp;
}
*/

void my::print_foo()
{
    std::cout << my::foo << '\n';
}

void my::print(int i)
{
    std::cout << i << '\n';
}