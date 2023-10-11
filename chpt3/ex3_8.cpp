#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    int val1;
    cout << "Please enter three integer values: ";
    cin >> val1;
    cout << "Value 1 = " << val1 << "\n";

    if (val1 % 2 == 0) {
        cout << "The value of " << val1 << " is even.\n"; 
    } else {
        cout << "The value of " << val1 << " is odd.\n"; 
    }

    return 0;
}