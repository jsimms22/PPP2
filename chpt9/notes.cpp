#include"std_lib_facilities.h"

using namespace std;

namespace Chrono 
{
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
            /* TODO */
            //return os << month_tbl[int(m)];
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

    void f(int m) { Enum_Notes::Month mm = Enum_Notes::int_to_month(m); }

    class Year
    {
        static const int s_min = 1800;
        static const int s_max = 2200;
    public:
        class Invalid { };
        Year() { };
        Year(int x) :y{x} { if (x < s_min || x > s_max) { throw Invalid{}; } }
        int year() const { return y; }
    private:
        int y;
    };

    class Date
    {
    /*
        We have options for default values:
            -use the default constructor
            -set them in the class (in-class initialization)
            -use static to get a variable
    */
    public:
        class Invalid { };                  // an object to throw as exception

        Date();                             // default constructor
        Date(Year);
        Date(Year,Enum_Notes::Month,int);   // 
        Date(Year,int,int);
        // why can I not put const here?
        // As soon as I made year(), month(), and day() "fn name() const" it was okay?
        const Date& default_date();    

        void add_day(int);
        bool is_date();

        // using const this way forces us at compile time to not modify return data
        int year() const { return y.year(); } 
        Enum_Notes::Month month() const { return m; };
        const int day() const { return d; }
        // ...
    private:
        Year y;
        Enum_Notes::Month m;
        unsigned int d;
    }; 

    const Date& Date::default_date()
    {
        // we use static here to create Date dd only once, instead of each time it is called
        // a reference return type is required to avoid copying dd
        static Date dd {2001,Enum_Notes::Month(Enum_Notes::Month::jan),1};
        return dd;
    }

    // Default Constructor
    // 2001 Jan 1
    Date::Date()
    {
        y = default_date().year();
        m = default_date().month();
        d = default_date().day();
    }

    // since values are not provided for Month and Day, 
    // they use the default constructor for values
    // yy Jan 1
    Date::Date(Year yy) 
        :y{yy} { if (!is_date()) { throw Invalid(); } }

    // yy mm dd
    Date::Date(Year yy, Enum_Notes::Month mm, int dd)
        :y{yy}, m{mm}, d{dd} { }

    Date::Date(Year yy, int mm, int dd)
    {
        y = yy;
        m = Enum_Notes::int_to_month(mm);
        d = dd;
    }

    void Date::add_day(int n) { /* todo */ }

    bool Date::is_date()
    {
        //if (m < 1 || 12 < m) { return false; }
        /* todo */
        //return true;
    }

    Date next_sunday(const Date& d) { /* TODO */ }

    Date next_workday(const Date& d) { /* TODO */}

    bool is_leapYear(int y) { /* TODO */}

    bool operator==(const Date& a, const Date& b)
    {
        return a.year()==b.year()
            && a.month()==b.month()
            && a.day()==b.day();
    }

    bool operator!=(const Date& a, const Date& b)
    {
        return !(a==b);
    }
}

int main() {
    Chrono::Enum_Notes::Month m = Chrono::Enum_Notes::Month::sept;
    Chrono::Date date = Chrono::Date(2019,Chrono::Enum_Notes::Month::mar,1);   // Runtime errror: day -1 does not make sense
    std::cout << date.year() << std::endl;

    Chrono::Date date2 = Chrono::Date(2019,1,1);   // Runtime errror: day -1 does not make sense
    std::cout << date.year() << std::endl;

    if (date == date2) { cout << "date == date2\n"; }

    // testing use of const Date& default_date() and default constructor
    vector<Chrono::Date> birthdays(10);
    for (Chrono::Date date : birthdays) {
        cout << "birthday (yyyy mm dd): " << date.year() /*<< " " << date.month()*/ << " " << date.day() << '\n'; 
    }

    if (birthdays[0] == birthdays[1]) { 
        cout << "[0] == [1]\n"; 
    } else { 
        cout << "[0] != [1]\n";
    }
}
