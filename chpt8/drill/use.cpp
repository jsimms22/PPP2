#include "my.hpp"

int main()
{
    foo = 7;
    print_foo();
    print(99);
    
    my::foo = 10;
    my::print_foo();
    my::print(77);

    hello_world();
}