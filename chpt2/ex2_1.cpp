#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

inline void keep_window_open() {
    cin.clear();
    cout << "Please enter a character to exit\n";
    char ch;
    cin >> ch;
    return;
}

int main() {                                        //C++ programs start by executing the function main
    cout << "Hello, programming!\nHere we go!\n";   //output "hello, world!"
    //cout << "Here we go!\n";
    keep_window_open();                             //wait for a character to be entered
    return 0;
}