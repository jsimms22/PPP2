#include<iostream>
#include<fstream>

int main()
{
    /*
        ios_base::app       -append
        ios_base::ate       -"at end"
        ios_base::binary    -binary mode
        ios_base::in        -for reading
        ios_base::out       -for writing
        ios_base::trunc     -truncate file to 0 length
    */

    std::string filename1 = "notes_file1.txt";
    std::ofstream of1 {filename1};  // defaults to iso_base::out

    std::string filename2 = "notes_file2.txt";
    std::ifstream if1 {filename2};  // defaults to iso_base::in

    std::string filename3 = "notes_file3.txt";
    std::ifstream of2 {filename3,std::ios_base::app};   // ofstreams by default include ios_base::out

    std::fstream fs {"myfile.txt",std::ios_base::in|std::ios_base::out};    // both in and out
}