#ifndef EXERCISE_H
#define EXERCISE_H

#include "std_lib_facilities.h"

namespace ex9_2
{
    class Name_Pairs
    {
    public:
        void read_names();
        void read_ages();
        void sort();



    //private:
        vector<std::string> name;
        vector<double> age;
    };

    ostream& operator<<(ostream& os, const Name_Pairs&);
    bool operator==(const Name_Pairs& a, const Name_Pairs& b);
    bool operator!=(const Name_Pairs& a, const Name_Pairs& b);
}
#endif