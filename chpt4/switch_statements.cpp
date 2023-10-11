#include<iostream>

using namespace std;

int main() { //case labels must be constants and distinct
    int y = 'y';
    constexpr char n = 'n';
    constexpr char m = '?';
    
    cout << "Do you like fish?\n";
    char a;
    cin >> a;

    switch (a) {
        case n:
            //...
            break;
        case y: //error: variable in case label
            //
            break;
        case m:
            //...
            break;
        case 'n': //error:duplicate case lebel
            //...
            break;
        default:
            //...
            break;
    }
}
