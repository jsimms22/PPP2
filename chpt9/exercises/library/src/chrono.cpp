#include "../../std_lib_facilities.h"
#include "../include/chrono.h"

namespace chrono
{
    Month int_to_month(int x)
    {
        if (x < int(Month::jan) || int(Month::dec) < x) { error("bad month"); }
        return Month(x);
    }

    Month operator++(Month& m)
    // Operator Overloading
    // ? -> arithmetic if
    // m becomes jan if (m == Month::dec) and Month(int(m)+1)
    {
        m = (m == Month::dec) ? Month::jan : Month(int(m)+1); // "wrap around"
        return m;
    }

    // This assumes we initialized month_tbl somewhere so that
    // month_tbl[int(month::mar)] is "march"; see 10.11.3
    // ostream& operator<<(ostream& os, Month m)
    // {   
    //     /* TODO */
    //     //return os << month_tbl[int(m)];
    // }

    const Date& Date::default_date()
    {
        // we use static here to create Date dd only once, instead of each time it is called
        // a reference return type is required to avoid copying dd
        static Date dd {2001,Month(Month::jan),1};
        return dd;
    }

    
    Date::Date()
    // Default Constructor
    // 2001 Jan 1
    {
        m_year = default_date().year();
        m_month = default_date().month();
        m_day = default_date().day();
    }

    
    Date::Date(Year yy)
    // since values are not provided for Month and Day, 
    // they use the default constructor for values
    // yy Jan 1 
        :m_year{yy} { if (!is_date(m_year.year(),Month::jan,1)) { throw Invalid(); } }

    
    Date::Date(Year yy, Month mm, int dd)
    // yy mm dd
        :m_year{yy}, m_month{mm}, m_day{dd} { }

    Date::Date(Year yy, int mm, int dd)
    {
        m_year = yy;
        m_month = int_to_month(mm);
        m_day = dd;
    }

    // void Date::add_day(int n) { /* todo */ }

    // void Date::add_month(int n) { /* TODO */}

    void Date::add_year(int n) 
    {
        // use march instead of february for non-leap years
        if (m_month==Month::feb && m_day==29 && !is_leapYear(m_year.year()+n)) {
            m_month = Month::mar;
            m_day = 1;
        }
        m_year.add_intYear(n);
    }
            
    bool is_date(int y, Month m, int d) 
    {
        // assume that y is valid
        if (d <= 0) { return false; }
        if (m < Month::jan || Month::dec < m) { return false; }

        int days_in_month = 31;

        switch (m) {
            case Month::feb:
                days_in_month = (is_leapYear(y))? 29 : 28;
                break;
            case Month::apr:
            case Month::jun:
            case Month::sept:
            case Month::nov:
                days_in_month = 30;
                break;
        }

        if (days_in_month < d) { return false; }

        return true;
    }

    // bool is_date(int y, int m, int d) { /* TODO */ }  // overloading is_date

    // bool is_leapYear(int y) { /* TODO */ }

    bool operator==(const Date& a, const Date& b)
    {
        return a.year()==b.year()
            && a.month()==b.month()
            && a.day()==b.day();
    }

    bool operator!=(const Date& a, const Date& b)
    {
        return !(a == b);
    }

    ostream& operator<<(ostream& os, const Date& d)
    {
        return os << '(' << d.year()
                  << ',' << d.month_to_int()
                  << ',' << d.day() << ')';
    }

    istream& operator>>(istream& is, Date& dd)
    {
        int y, m, d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        if (!is) { return is; }
        if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
            is.clear(ios_base::failbit);
            return is;
        }

        dd = Date(y,int_to_month(m),d);
        
        return is;
    }

    // Day day_of_week(const Date& d) { /* TODO */}

    // Date next_sunday(const Date& d) { /* TODO */ }

    // Date next_workday(const Date& d) { /* TODO */}
} // Chrono
