#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    cout << "Please enter your first name and age:\n";
    string first_name;  //first_name is a variable of string type
    double age;
    cin >> first_name >> age;  //reads console input into the variable first_name

    cout << "Hello, " << first_name << " (age in years: " << age << ")!\n";
    cout << "Hello, " << first_name << " (age in months: " << (age * 12) << ")!\n";

    return 0;
}