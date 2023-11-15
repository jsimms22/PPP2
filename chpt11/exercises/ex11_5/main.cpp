#include<iostream>
#include<sstream>
#include<vector>
#include<string>

void char_classifier(const std::string& s)
{
    std::stringstream strs {s};
    for (char ch; strs.get(ch); ) {
        std::cout << ch << ": ";
        if (isspace(ch)) { std::cout << "is a space, "; }
        if (isdigit(ch)) { std::cout << "is a digit, "; }
        if (isalpha(ch)) { std::cout << "is a letter, "; }
        if (isxdigit(ch)) { std::cout << "is a hex digit, "; }
        if (isupper(ch)) { std::cout << "is an upper case, "; }
        if (islower(ch)) { std::cout << "is a lower case, "; }
        if (isalnum(ch)) { std::cout << "is an alphanumeric, "; }
        if (iscntrl(ch)) { std::cout << "is a control character, "; }
        if (ispunct(ch)) { std::cout << "is a punctuation, "; } 
        if (isprint(ch)) { std::cout << "is printable, "; }
        if (isgraph(ch)) { std::cout << "is a letter, or digit, or punctuation, "; }
        std::cout << '\n';
    }
}

int main()
{
    std::string s;
    std::cin >> s;

    char_classifier(s);
}