#include<iostream>
#include<fstream>
#include<cstring>
#include<utility>
#include<vector>

bool isvowel(char ch)
{
    ch = tolower(ch);
    switch(ch) {
        case 'a': case 'e': case 'i':
        case 'o': case 'u': case 'y':
            return true;
        default:
            return false;
    }
}

void disemvowel(std::string& s)
{
    std::string temp;
    for (char ch : s) {
        if (!isvowel(ch)) { temp.push_back(ch); }
    }
    s = temp;
}

int main()
{
    try {
        std::ifstream ifs {"input.txt"};
        std::ofstream ofs {"output.txt"};

        char c;
        while (ifs.get(c)) {
            if (isgraph(c) || isspace(c)) {
                if (!isvowel(c)) { ofs << c; }
            }
        }

        ifs.close();
        ofs.close();
    } catch (std::exception& e) {
        std::cout << e.what() << '\n';
    } catch (...) { }
}