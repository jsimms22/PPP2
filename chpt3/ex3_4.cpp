#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    int val1;
    cout << "Please enter an integer value:";
    cin >> val1;
    cout << "Value 1 = " << val1 << "\n";

    int val2;
    cout << "Enter one more: ";
    cin >> val2;
    cout << "Value 2 = " << val2 << "\n";

    if (val1 > val2) { 
        cout << val1 << " is bigger than " << val2 << "\n";
    } else if (val2 > val1) {
        cout << val2 << " is bigger than " << val1 << "\n";
    } else {
        cout << "values are the same number.\n";
    }

    cout << val1 << " + " << val2 << " = " << val1 + val2 << ".\n";
    cout << val1 << " - " << val2 << " = " << val1 - val2 << ".\n";
    cout << val1 << " * " << val2 << " = " << val1 * val2 << ".\n";
    cout << val1 << " / " << val2 << " = " << val1 / val2 << " with remainder of " << val1 % val2 << ".\n";
    
    return 0;
}