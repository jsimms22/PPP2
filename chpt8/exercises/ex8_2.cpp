/*
	This program solves Exercises 2, 3, 4, 5

    From Chapter 8
*/

#include<iostream>
#include<vector>
#include<string>

void print_vec(std::vector<int> v, std::string s)
// prints a given vector, with label s
{
    std::cout << "Printing Vector: " + s << '\n';
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ' ';
        if (i == (v.size() - 1)) { std::cout << '\n'; }
    }
}

void fibi(int x, int y, std::vector<int>& v, int n)
// produces element for vector v using a fibonacci sequence
// x -> first element
// y -> second element
// v -> vector to be filled
// n -> max number of elements for v
{
    v.push_back(x);
    v.push_back(y);
    for (int i = 2; i < (n); i++) {
        v.push_back(v[i-1] + v[i-2]);   // v[i] = v[i-1] + v[i-2]
    }
}

std::vector<int> flip_ver1(std::vector<int>& v1)
// creates new vector with reverse of given vector and returns new vector
{
    std::vector<int> v2(v1.size());
    int j = 0;
    for (int i = (v1.size()-1); i >= 0; i--) {
        v2[j] = v1[i];
        j++;
    }
    return v2;
}

void flip_ver2(std::vector<int>& v)
// flips provided vector and returns flipped vector
{
    int j = 0; int temp;
    for (int i = (v.size()-1); i >= 0; i--) {
        if (i <= j) break;
        temp = v[j];
        std::swap(v[i],temp);
        v[j] = temp;
        j++;
    }
}

int main() 
{
    std::vector<int> v1;
    int n = 10;
    fibi(0,1,v1,n);
    print_vec(v1,"v1 vec");

    std::vector<int> v2 = flip_ver1(v1);
    print_vec(v2,"v2 vec");

    flip_ver2(v1);
    print_vec(v1,"v1 vec flipped");

}