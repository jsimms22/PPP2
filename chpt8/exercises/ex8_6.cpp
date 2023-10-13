/*
	This program solves Exercises 6

    From Chapter 8
*/

#include<iostream>
#include<vector>
#include<string>

//using namespace std;

void print_vec(std::vector<std::string> v, std::string s)
// prints a given vector, with label s
{
    std::cout << "Printing Vector: " + s << '\n';
    for (std::string name : v) {
        std::cout << name << ' ';
    }
    std::cout << '\n';
}

void initialize_vec(std::vector<std::string>& v, int n)
{
    if (n <= 0) { return; }
    int i = 0;
    for (std::string name; std::cin >> name; i++) {
        v.push_back(name);
        if (i == n) break;
    }
}

std::vector<std::string> flip_ver1(std::vector<std::string>& v1)
// creates new vector with reverse of given vector and returns new vector
{
    std::vector<std::string> v2(v1.size());
    int j = 0;
    for (int i = (v1.size()-1); i >= 0; i--) {
        v2[j] = v1[i];
        j++;
    }
    return v2;
}

void flip_ver2(std::vector<std::string>& v)
// flips provided vector and returns flipped vector
{
    int j = 0; std::string temp;
    for (int i = (v.size()-1); i >= 0; i--) {
        if (i <= j) break;
        temp = v[j];
        std::swap(v[i],temp);
        v[j] = temp;
        j++;
    }
}

int main(int argc, char **argv) 
{
    std::vector<std::string> v1;
    int n = argc-1; //  we only want n many elements in vector v
    initialize_vec(v1,n);
    print_vec(v1,"v1 vec");

    std::vector<std::string> v2 = flip_ver1(v1);
    print_vec(v2,"v2 vec");

    flip_ver2(v2);
    print_vec(v2,"v2 vec flipped");
}