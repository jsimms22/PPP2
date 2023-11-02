#include<iostream>
#include<fstream>

#include "../../std_lib_facilities.h"

struct Point {
    int x;
    int y;
};

int main(int argc, char** argv)
{
    std::string filename = "nofile";
    if (argc < 2) { 
        error("no file name given as argument");
    } else if (argc > 2) {
        error("too many arguments given");
    } else {
        filename = argv[1]; // index 0 would be the .exe
    }
    std::ofstream ost {filename};
    if(!ost) { error("coult not open: ", filename); }

    vector<int> original_points;
    cout << "input some integer values for testing: \n";
    while (original_points.size() < 7) {
        int i;
        if (!(std::cin>>i)) break;
        original_points.push_back(i);
    }

    for (int element : original_points) {
        std::cout << element << " ";
    }
    cout << '\n';

    for (int element : original_points) {
        ost << element << '\n';
    }
    cout << '\n';

    ost.close();

    std::ifstream ist {filename};
    int temp;
    vector<int> processed_points;
    while (ist >> temp) {
        processed_points.push_back(temp);
    }

    for (int i = 0; i < processed_points.size() && i < original_points.size(); i++) {
        std::cout << original_points[i] << " " << processed_points[i] << '\n';
        if ( original_points[i] != processed_points[i]) { error("original and processed points are not equal"); }
    }
    ist.close();
}