#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    string val1; string val2; string val3;
    cout << "Please enter three integer values: ";
    cin >> val1 >> val2 >> val3;

    if (val1 > val2) { swap(val1, val2); }

    if (val1 > val3) { swap(val1, val3); }

    if (val2 > val3) { swap(val2, val3); }

    cout << val1 << ", " << val2 << ", " << val3;

    return 0;
}