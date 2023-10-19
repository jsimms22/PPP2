#include "Chrono.h"
#include "std_lib_facilities.h"

using namespace Chrono;

int main() 
{
    Month m = Month::sept;
    Date date = Date(2019,Month::mar,1);   // Runtime errror: day -1 does not make sense
    cout << date.year() << std::endl;

    Date date2 = Date(2019,3,1);   // Runtime errror: day -1 does not make sense
    cout << date.year() << endl;

    if (date == date2) { cout << "date == date2\n"; }

    // testing use of const Date& default_date() and default constructor
    vector<Date> birthdays(10);
    for (Date date : birthdays) {
        cout << "birthday (yyyy mm dd): " << date.year() /*<< " " << date.month()*/ << " " << date.day() << '\n'; 
    }

    if (birthdays[0] == birthdays[1]) { 
        cout << "[0] == [1]\n"; 
    } else { 
        cout << "[0] != [1]\n";
    }

    Date today = Date(2023,2,28);
    Date tomorrow = today;
    tomorrow.add_day(31);

    cout << "today: " << today << '\n';
    cout << "tomorrow: " << tomorrow << '\n';
}