#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    int val1; int val2; int val3;
    cout << "Please enter three integer values: ";
    cin >> val1;
    cout << "Value 1 = " << val1 << "\n";
    cin >> val2;
    cout << "Value 2 = " << val2 << "\n";
    cin >> val3;
    cout << "Value 2 = " << val2 << "\n";

    if (val1 > val2) { swap(val1, val2); }

    if (val1 > val3) { swap(val1, val3); }

    if (val2 > val3) { swap(val2, val3); }

    cout << val1 << ", " << val2 << ", " << val3;

    return 0;
}
