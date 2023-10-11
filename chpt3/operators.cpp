#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    cout << "Please enter a floating-point value:";
    double n;
    cin >> n;

    cout << "\nn == " << n+1
         << "\nthree times n == " << n*3
         << "\ntwice n == " << n*2
         << "\nn squared == " << pow(n,2) //pow is slower for small exponent values
         << "\nhalf of n == " << n / 2
         << "\nsquare root of n == " << sqrt(n)
         << "\n";

    cout << "Please enter an integer value:";
    int i;
    cin >> i;

    cout << "\nn == " << i+1
         << "\nthree times n == " << i*3
         << "\ntwice n == " << i*2
         << "\nn squared == " << pow(i,2) //pow is slower for small exponent values
         << "\nhalf of n == " << i / 2 
         << ", where the remainder is == " << i % 2
         << "\nsquare root of n == " << sqrt(i) //sqrt returns a floating point value
         << "\n";

    return 0;
}