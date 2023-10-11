#include<iostream>
#include<string>

using namespace std;

//this is a simple program showing some very limited uses of reporting errors. Not a good benchmark.//
char ask_user(string question) {
    cout << question << " yes or no\n";
    string answer;
    cin >> answer;

    if (answer == "y" || answer == "yes") { return 'y'; }
    if (answer == "n" || answer == "no") { return 'n'; }
    return 'b'; // 'b' for bad answer
}

int area(int length, int width) {
    if (length <= 0 || width <= 0) { return -1; }
    return length * width;
}

int main() {
    string question_input = "Have you brushed your teeth today?";
    char answer = ask_user(question_input);
    cout << answer << '\n';

    int val1, val2;
    cout << "Input two integers.\n";
    cin >> val1 >> val2;
    if (area(val1, val2) == -1) { return -1; }
    else { return 0; }
}