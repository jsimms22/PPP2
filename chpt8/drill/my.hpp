#include<iostream>

//inline int foo    // alternatively this does not require a definition in my.cpp
extern int foo;     // declaring foo as extern variable
void print_foo();   // functions have extern linkage by default
void print(int);
void swap_v(int,int);
void swap_r(int&,int&);
void swap_r(double&,double&);
//void swap_cr(const int&,const int&);

namespace my
{
    extern int foo; // declaring my::foo as extern variable
    void print_foo();
    void print(int);
} // namespace my

inline void hello_world()   // functions defined in header files requires inline keyword
{
    std::cout << "Hello, World from my.hpp" << '\n';
}

// https://www.reddit.com/r/C_Programming/comments/g7zyzs/need_help_in_understanding_static_extern_and/


