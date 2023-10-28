#ifndef EXERCISE_H
#define EXERCISE_H

//#include "std_lib_facilities.h"
#include<vector>
#include<string>
#include "std_lib_facilities.h"

namespace ex9_2
{
    class Name_Pairs
    {
    public:
        void read_names();
        void read_ages();
        void sort();
        vector<std::string> get_names() const { return names; }
        vector<double> get_ages() const { return ages; }
    private:
        vector<std::string> names;
        vector<double> ages;
    };

    std::ostream& operator<<(std::ostream& os, const Name_Pairs&);
    bool operator==(const Name_Pairs& a, const Name_Pairs& b);
    bool operator!=(const Name_Pairs& a, const Name_Pairs& b);
}
#endif