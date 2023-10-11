#include<iostream>
#include<cmath>

using namespace std;

int main() {
    double dc;
    cin >> dc;
    double df = 9/5 * dc + 32; //this is incorrect, 9/5 is an integer
    cout << df << "\n";

    df = 9.0/5.0 * dc + 32; //this is correct, 9.0/5 at minimum to guarentee FP precision
    cout << df << "\n";
    df = 9/5.0 * dc + 32;
    cout << df << "\n";
    df = 9.0/5 * dc + 32;
    cout << df << "\n";
    df = (double)9/5 * dc + 32; //if you did (9/5), then it would be incorrect
    cout << df << "\n";
}