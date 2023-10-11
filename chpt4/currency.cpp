#include<iostream>

using namespace std;
/*
int main() {
    constexpr double yen_per_dollar = 148.31;
    constexpr double kroner_per_dollar = 10.81;
    constexpr double pound_per_dollar = .81;

    double amount = 1;

    char unit = ' ';
    cout << "Please enter an amount of money followed by a currency marker (y (yen), k (kroner), or p (pound)):\n";
    cin >> amount >> unit;

    if (unit == 'y') { // yen
        cout << amount << " yen == " << yen_per_dollar/amount << " dollars\n";
    } else if (unit == 'k') { // kroner
        cout << amount << " kroner == " << kroner_per_dollar/amount << " dollars\n";
    } else if (unit == 'p') { // pounds
        cout << amount << " pound == " << pound_per_dollar/amount << " dollars\n";
    } else {
        cout << "Sorry I do not know a currency called " << unit << "\n";
    }

    return 0;
}
*/

int main() {
    constexpr double yen_per_dollar = 148.31;
    constexpr double kroner_per_dollar = 10.81;
    constexpr double pound_per_dollar = .81;

    double amount = 1;

    char unit = ' ';
    cout << "Please enter an amount of money followed by a currency marker " <<
            "(y (yen), k (kroner), p (pound), or d (dollars)):\n";
    cin >> amount >> unit;

    char unit2 = ' ';
    if (unit == 'd') {
        cout << "What currency do you want to convert your dollars to?\n";
        cin >> unit2;
    }

    switch (unit) {
        case 'y':
            cout << amount << " yen == " << yen_per_dollar / amount << " dollars\n";
            break;
        case 'k':
            cout << amount << " kroner == " << kroner_per_dollar / amount << " dollars\n";
            break;
        case 'p':
            cout << amount << " pound == " << pound_per_dollar / amount << " dollars\n";
            break;
        case 'd':
            if (unit2 == 'y') { // yen
                cout << amount << " dollars == " << amount * yen_per_dollar << " yen\n";
            } else if (unit2 == 'k') { // kroner
                cout << amount << " dollars == " << amount * kroner_per_dollar << " kroner\n";
            } else if (unit2 == 'p') { // pounds
                cout << amount << " dollars == " << amount * pound_per_dollar << " pounds\n";
            } else {
                cout << "Sorry I do not know a currency called " << unit2 << "\n";
            }
            break;
        default:
            cout << "Sorry I do not know a currency called " << unit << "\n";
            break;
    }   
}