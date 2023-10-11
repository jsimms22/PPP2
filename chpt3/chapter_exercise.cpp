#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

inline void simple_error(string s)	// write ``error: s and exit program
{
	cerr << "error: " << s << '\n';
	exit(1);
}

int main() {
    string from_name;
    cout << "What is your first name: ";
    cin >> from_name;
    cout << "Hello, " << from_name << "\n";

    string to_name;
    cout << "Enter the name of the person you want to write to: ";
    cin >> to_name;
    cout << "Dear, " << to_name << "\n";

    cout << "   I love potatos. I miss potatos. Please send potatos.\n";

    string friend_name; 
    char friend_sex;
    cout << "Name a friend you would like to write about: ";
    cin >> friend_name;
    cout << "Is this friend male (m), or female (f): ";
    cin >> friend_sex;

    cout << "   Have you seen " << friend_name << " lately? ";
    
    if (friend_sex == 'm') { 
        cout << "If you see " << friend_name << ", please ask him to call me.\n"; 
    } else if (friend_sex == 'f') {
        cout << "If you see " << friend_name << ", please ask her to call me.\n";
    } else {
        cout << "If you see " << friend_name << ", please ask them to call me.\n";
    }
    
    int to_name_age;
    cout << "How old is " << to_name << "? ";
    cin >> to_name_age;

    if (to_name_age <= 0) { 
        simple_error("You're kidding me!"); 
    } if (to_name_age >= 110) {
        simple_error("You're kidding me!"); 
    } if (to_name_age == 12) {
        cout << "   Next year you will be " << (to_name_age + 1) << ".\n";
    } if (to_name_age == 17) {
        cout << "   Next year you will be to vote!\n";
    } if (to_name_age > 70 && to_name_age < 110 ) {
        cout << "   I hope you are enjoying retirement.\n";
    } else {
        cout << "   Next year you will be " << (to_name_age + 1) << ".\n";
    }

    cout << "Sincerely " << from_name << "\n";

    return 0;
}