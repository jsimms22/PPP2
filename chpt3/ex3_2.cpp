#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    double miles;
    cout << "Welcome to Miles-to-Kilometers Converter!\n"
         << "Please enter how many miles: ";
    cin >> miles;

    cout << "\nThat is " << miles * 1.609 << " kilometers!\n"; 

    return 0;
}