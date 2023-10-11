#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    double d = 0;
    while (cin >> d) {
        int i = d; //no error, possible loss of information
        char c = i; //no error, possible loss of information
        int i2 = c;
        cout << "d==" << d << "\n"
             << "i==" << i << "\n"
             << "c==" << c << "\n"
             << "i2==" << i2 << "\n";
    }

    // side-note: only 0-127 can be used portably beyond Windows,
    // PC stores chars (-128,127], others may be [0,255]

    return 0;
}