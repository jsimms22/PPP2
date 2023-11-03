/*
    solutions for exercise 3
        -this program will take in the name of a data file as an argument
        -calculate 50 random integer-typed temperatured separated by whitespace in file
        -read values from file and store in a vector
        -calculates the mean and average

*/
#include<fstream>
#include<iostream>
#include<vector>
#include<ctime>
#include "temps.h"
#include "../../../std_lib_facilities.h"

int nTemps = 50;

void build_file(std::string& name)
{
    std::ofstream ost {name};   // ost is an alias for cout that write to file: name
    for (int i = 0; i < nTemps; i++) {
        ost /*<< i << " " */<< rand()%100 << ' ';//'\n';  // generating random temperatures [0-100) for a day
    }
    ost.close();
}

void fill_vector(istream& ist, vector<Reading> &v, char terminator)
{
    //int hour;
    double temp;
    while(ist /*>> hour */>> temp) { v.push_back(Reading{/*hour,*/temp}); }
    if (ist.eof()) { return; }

    // ist.exceptions and the way it is used allows us to simply care
    // for cases when ist becomes fail()
    ist.clear();

    char c;
    ist >> c;
    if (c != terminator) {
        cout << "istream terminated\n";
        ist.unget();
        ist.clear(ios_base::failbit);
    }
}

void fill_from_file(vector<Reading>& r, std::string& name)
// read in from a given file: name
{
    std::ifstream ist {name};   // ist is an alias for cin that will ingest file: name
    ist.exceptions(ist.exceptions()|ios_base::badbit);  //  throws exception: failure if ist becomes bad()
    fill_vector(ist,r,'*');     // provide istream alias, vector to fill, and a panic character
    ist.close();
}

int main(int argc, char** argv) //argc is number of arguments + 1, since the name of the program will prepend to array argv
{
    std::string filename = "nofile";
    if (argc < 2) { 
        error("no file name given as argument");
    } else if (argc > 2) {
        error("too many arguments given");
    } else {
        filename = argv[1]; // index 0 would be the .exe
    }

    srand(time(NULL));
    vector<Reading> data;

    if (filename == "nofile") { error("could not read given filename"); }
    std::cout << "Attempting to write to: " + filename << '\n';
    build_file(filename);

    std::cout << "Attempting to read from: " + filename << '\n';
    fill_from_file(data,filename);
    for (Reading datum : data) {
        std::cout /*<< "hour : " << datum.hour << '\t' */<< "temperature: " << datum.temp << '\n'; 
    }

    double mean_temp = mean(data);
    std::cout << "average temp: " << mean_temp << '\n';
    double median_temp = median(data);
    std::cout << "median temp: " << median_temp << '\n';

    build_file(filename);
}