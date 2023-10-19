#ifndef EXERCISE_H
#define EXERCISE_H

#include<string>
#include<vector>
#include<iostream>

namespace ex9_2
{
    class Name_Pairs
    {
    public:
        void read_names();
        void read_ages();
        void sort();
    
        //std::ostream& operator<<(std::ostream& os, const std::vector<std::string> names);
        /*
        bool operator==(const Name_Pairs a, const Name_Pairs b);
        bool operator!=(const Name_Pairs a, const Name_Pairs b);
        */

    //private:
        std::vector<std::string> name;
        std::vector<double> age;
    };
}
#endif