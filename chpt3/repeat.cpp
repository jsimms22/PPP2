#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
    string previous = "";
    string current;
    int num_of_word = 0;
    while (cin >> current) {
        ++num_of_word;
        if ( previous == current ) {
            cout << "Word number: " << num_of_word << ".\n";
            cout << "Repeated word: " << current << "\n";
        }
        previous = current;
    }

    return 0;
}