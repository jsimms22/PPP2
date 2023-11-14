#include<iostream>
#include<iomanip>

int main()
{
    int birth_year = 1994;
    std::cout << birth_year << " (decimal)" << std::showbase << "\t\t"
              << std::hex << birth_year << " (hexidecimal)\t"
              << std::oct << birth_year << " (octal)\n";

    std::cout << "I am " << std::dec << 29 << " years old\n";

    int a, b, c, d;
    /*
        input: 1234 1234 1234 1234
        output: 1234    668     4660    4660

        changing the base for cin does not affect cout
        cout is still outputting decimal

        so while the input is in its respective base, the output
        is converted to decimal
    */
    std::cin >> a >> std::oct >> b >> std::hex >> c >> d;
    std::cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';


    /*
        output: 
            1.23457e+06     (defaultfloat)
            1234567.890000  (fixed)
            1.234568e+06    (scientific)
        
        default float attempts to resolve the number in the "cleanest" manner
        in this case it chose scientific since there are more than 6 sig figs

        fixed will round to a certain decimal (changable amount)

        scientific should be obvious
    */
    std::cout << 1234567.89 << "\t(defaultfloat)\n"   // \t\t for formating
              << std::fixed << 1234567.89 << "\t(fixed)\n"
              << std::scientific << 1234567.89 << "\t(scientific)\n";

    /*
        simple table
    */
     std::cout << '|' << std::setw(8) << "jeremiah" << '|' << std::setw(8) << "simmons" << '|' << std::setw(18) << "jeremiah@mail.com" << "|\n"
               << '|' << std::setw(8) << "sara"     << '|' << std::setw(8) << "conley"  << '|' << std::setw(18) << "sara@mail.com"     << "|\n"
               << '|' << std::setw(8) << "thomas"   << '|' << std::setw(8) << "ruland"  << '|' << std::setw(18) << "thomas@mail.com"   << "|\n"
               << '|' << std::setw(8) << "jon"      << '|' << std::setw(8) << "bunton"  << '|' << std::setw(18) << "jon@mail.com"      << "|\n"
               << '|' << std::setw(8) << "ricky"    << '|' << std::setw(8) << "borges"  << '|' << std::setw(18) << "ricky@mail.com"    << "|\n";
}