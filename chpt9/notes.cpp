#include"std_lib_facilities.h"

using namespace std;

namespace Enum_Notes 
{
    enum class Month
    {
        jan=1,  // we choose to start enumeration at position '1'
        feb,
        mar,
        apr,
        jun,
        jul,
        aug,
        sept,
        oct,
        nov,
        dec
    };

    enum class Day
    {
        monday, // enums start at position '0' by default
                // monday == 0, tuesday == 1
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday,
        sunday
    };

    Month int_to_month(int x)
    {
        if (x < int(Month::jan) || int(Month::dec) < x) { error("bad month"); }

        return Month(x);
    }

    // Operator Overloading
    Month operator++(Month& m)
    // ? -> arithmetic if
    // m becomes jan if (m == Month::dec) and Month(int(m)+1)
    {
        m = (m == Month::dec) ? Month::jan : Month(int(m)+1); // "wrap around"

        return m;
    }

    // This assumes we initialized month_tbl somewhere so that
    // month_tbl[int(month::mar)] is "march"; see 10.11.3
    ostream operator<<(ostream& os, Month m)
    {
        return os << month_tbl[int(m)];
    }
}

namespace Plain_Enum 
{
    enum Month
    {
        jan=1,  // we choose to start enumeration at position '1'
        feb,
        mar,
        apr,
        jun,
        jul,
        aug,
        sept,
        oct,
        nov,
        dec
    };

    // Examples of using "Plain" enums
    Month m = feb;
    Month m2 = Month::feb;
    //m = 7;  // error: cannot assign an int to Month
    int n = m;
    Month mm = Month(7);
}

class Date
{
public:
    class Invalid { };
    Date(int y, Enum_Notes::Month m, int d);
    void add_day(int n);
    Enum_Notes::Month month();
    // ...
private:
    int y, d;
    Enum_Notes::Month m;
    bool is_valid();
};

Date::Date(int yy, Enum_Notes::Month mm, int dd) 
    :y{yy}, m{mm}, d{dd} { }

void Date::add_day(int n) { /* todo */ }

Enum_Notes::Month Date::month() { return m; }

bool Date::is_valid()
{
    if (m < 1 || 12 < m) { return false; }
    /* todo */
    return true;
}

void f(int m)
{
    Enum_Notes::Month mm = Enum_Notes::int_to_month(m);
}

int main()
{
    Enum_Notes::Month m = Enum_Notes::Month::sept;
}
// attempting change
