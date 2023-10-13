#include "my.hpp"

int main()
{
    foo = 7;
    print_foo();
    print(99);

    int x = 7; int y = 9;
    std::cout << "initial values: " << x << '\t' << y << '\n';
    swap_v(x,y);    // this will copy x and y, and will NOT swap here
    std::cout << "swap_v results: " << x << '\t' << y << '\n';

    int& xr = x; int& yr = y;
    std::cout << "initial values: " << xr << '\t' << yr << '\n';
    swap_r(xr,yr);  // this will pass references to xr and yr, and will swap here
    std::cout << "swap_r results: " << xr << '\t' << yr << '\n';

    /*
    const int& xcr = xr; const int& ycr = yr;
    std::cout << "initial values: " << xcr << '\t' << ycr << '\n';
    swap_cr(xcr,ycr);   // will not compile
    std::cout << "swap_cr results: " << xcr << '\t' << ycr << '\n';
    */

    double dx = 7.7; double dy = 9.9;
    double& dxr = dx; double& dyr = dy;
    std::cout << "initial values: " << dxr << '\t' << dyr << '\n';
    swap_r(dxr,dyr);  // this will pass references to dxr and dyr, and will swap here
    std::cout << "swap_r results: " << dxr << '\t' << dyr << '\n';

    // declared within a specific namespace "my"
    my::foo = 10;
    my::print_foo();
    my::print(77);

    hello_world();  // inline defined function
}