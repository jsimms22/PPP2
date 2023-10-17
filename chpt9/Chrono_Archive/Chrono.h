namespace Chrono 
{
    enum class Day
    {
        monday, tuesday, wednesday, thursday, 
        friday, saturday, sunday
    };

    enum class Month
    { // we choose to start enumeration at position '1'
        jan=1, feb, mar, apr, may, jun, 
        jul, aug, sept, oct, nov, dec
    };

    Month int_to_month(int);
    Month operator++(Month&);
    ostream operator<<(ostream&,Month);

    class Year
    {
        static const int s_min = 1800;
        static const int s_max = 2200;
    public:
        class Invalid { };  // an object to throw as exception
        Year() { };
        Year(int x) :y{x} { if (x < s_min || x > s_max) { throw Invalid{}; } }
        int year() const { return y; }
        void add_intYear(int x) { y += x; }
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
        class Invalid { };      // an object to throw as exception

        Date();                 // default constructor
        Date(Year);             // constructor with only year
        Date(Year,Month,int);   // constructor with year, month enum, ## day of month
        Date(Year,int,int);     // constructor with year, ## month, ## day of month
        
        // As soon as I made year(), month(), and day() = 
        // "fn name() const" this worked
        const Date& default_date();     

        // non-modifying operators
        int day() const { return d; }
        Month month() const { return m; };
        int month_to_int() const { return (int)m; }
        int year() const { return y.year(); } 

        // modifying operators
        void add_day(int);
        void add_month(int);
        void add_year(int);

    private:
        Year y;
        Month m;
        int d;
    }; 

    bool is_date(int y, Month m, int d);
    bool is_date(int y, int m, int d);  // overloading is_date
    bool is_leapYear(int y);

    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    ostream& operator<<(ostream& os, const Date& d);
    istream& operator>>(istream& is, const Date& dd);

    Day day_of_week(const Date& d);
    Date next_sunday(const Date& d);
    Date next_workday(const Date& d);
} // Chrono