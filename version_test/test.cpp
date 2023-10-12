#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2{v1}; // C++14 style copy construction

    vector<int> v3;
    vector<int> v2 = v1; // C++98 style copy construction

    return 0;
}