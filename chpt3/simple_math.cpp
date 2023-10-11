#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() { 
    int count;
    cin >> count;
    string name;
    cin >> name;

    int c2 = count +2;
    string s2 = name + "Jr.";

    int c3 = count-2;
    // string s3 = name - "Jr."; //creates compile error

    return 0;
}