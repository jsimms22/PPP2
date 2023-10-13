#include<iostream>

namespace X
{
    int var;
    void print() { std::cout << "x::print var = " << var << '\n'; }
} // namespace X

namespace Y
{
    int var;
    void print() { std::cout << "y::print var = " << var << '\n'; }
} // namespace Y

namespace Z
{
    int var;
    void print() { std::cout << "z::print var = " << var << '\n'; }    
} // namespace Z

int main()
{
    X::var = 7;
    X::print();         // print x::var

    using namespace Y;  
    var = 9;
    print();            // print y::var

    {
        using Z::var;
        using Z::print;
        var = 11;
        print();        // print z::var
    }

    print();            // print y::var
    X::print();         // print x::var
}

