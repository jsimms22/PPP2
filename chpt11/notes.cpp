#include<iostream>
#include<iomanip>

// found out: if I give 1234567.0 as the input to the VERY first cin in this program, input gets stuck for every other cin
// this provides a very good example for understanding why handling cin properly is important

int main()
{
    
    /*
        this prints:
        1234    4d2     2322
        2322
        1234   
    */
    std::cout << 1234 << '\t' << std::hex << 1234 << '\t' << std::oct << 1234 << '\n';
    std::cout << 1234 << '\n';  // the use of oct, hex, dec persist until otherwise told to change
    std::cout << std::dec << 1234 << "\n\n";

    /*
        this prints:
        1234    0x4d2   02322

        hex has prefix 0x
        oct has prefix 0
    */
    std::cout << std::showbase << std::dec;
    std::cout << 1234 << '\t' << std::hex << 1234 << '\t' << std::oct << 1234 << "\n\n";
    std::cout << std::noshowbase;   // reverses the action of showbase

    /*
        this prints:
        1234    1234    1234
    */
    std::cout << std::dec;
    std::cout << 1234 << '\t' << 0x4d2 << '\t' << 02322 << "\n\n";

    /*
        given:
        1234 4d2 2322 2322

        this prints:
        1234    1234    1234    1234
    */
    int a, b, c, d;
    std::cin >> a >> std::hex >> b >> std::oct >> c >> d;   // changing base input here will not change base output below
    std::cout << a << '\t' << b << '\t' << c << '\t' << d << "\n\n";  // this is still printing in base-10 from line 31

    // we can get >> to accept and interpret base identifiers like 0 and 0x by using unset
    // the stream member function unsetf() clears the flag or flags given as argument
    std::cin.unsetf(std::ios::dec); 
    std::cin.unsetf(std::ios::oct); 
    std::cin.unsetf(std::ios::hex);

    /*
        given:
        1234 0x4d2 02322 02322

        this prints:
        1234    1234    1234    1234
    */
    std::cin >> a >> std::hex >> b >> std::oct >> c >> d;
    std::cout << a << '\t' << b << '\t' << c << '\t' << d << "\n\n";

    /*
        this prints:
        1234.57         (defaultfloat)
        1234.567890     (fixed)
        1.234568e+03    (scientific)
    */
    // dealing with scientific computation and floating points
    std::cout << 1234.56789 << "\t\t(defaultfloat)\n"   // \t\t for formating
              << std::fixed << 1234.56789 << "\t(fixed)\n"
              << std::scientific << 1234.56789 << "\t(scientific)\n\n";

    // 1234567.0 cannot be formatted using the fixed format using only six digits
    // so the output switches to scientific
    std::cout << std::defaultfloat << 1234567.0 << "\n\n";
    // defaultfloat will attempt to present the number in the most appropriate format it believes to be correct

    // we can set precisison manually with setprecision();
    /*
        1234.57             1234.567890             1.234568e+03
        1234.6              1234.56789              1.23457e+03
        1234.5679           1234.56789000           1.23456789e+03
    */
    std::cout << 1234.56789 << "\t\t"
              << std::fixed << 1234.56789 << "\t\t"
              << std::scientific<< 1234.56789 << '\n';
    std::cout << std::defaultfloat << std::setprecision(5)
              << 1234.56789 << "\t\t"
              << std::fixed << 1234.56789 << "\t\t"
              << std::scientific<< 1234.56789 << '\n';
    std::cout << std::defaultfloat << std::setprecision(8)
              << 1234.56789 << "\t"
              << std::fixed << 1234.56789 << "\t\t"
              << std::scientific<< 1234.56789 << '\n';
}