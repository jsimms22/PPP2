#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    cout << "Please enter your first and last names:\n";
    string first; string last;
    cin >> first >> last;
    string name = first + " " + last;
    cout << "Hello " << name << "\n";

    if (first == last) cout << "That's the same name twice!\n";
    if (first < last) cout << first << " is alphabetically before " << last << "\n";
    if (first > last) cout << last << " is alphabetically before " << first << "\n";

    return 0;
}