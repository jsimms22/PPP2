#include<iostream>
#include<fstream>
#include<vector>

int main()
{
    /*
        read in a text file
        convert its input to lower
        write output to new file
    */

    std::ifstream ifs {"text.txt"};     // read in file with sample text
    std::vector<std::string> word_bin;  
    for (std::string s; ifs >> s; ) {   
        word_bin.push_back(s);          // store sample text in vector (preserve punctuation as part of a word)
    }

    // for each element of vector, check each char in each 
    // element and change case to lower if needed
    for (std::string& element : word_bin) {
        for (char& ch : element) {
            if (isalpha(ch) && isupper(ch)) { ch = tolower(ch); } 
        }
    }

    std::string new_filename = "new_text.txt";  
    std::ofstream ofs {new_filename};           // open ofstream to new file

    for (std::string const element : word_bin) { 
        ofs << element << " ";                  // write vector elements to file}
    }
    
    ifs.close();
    ofs.close();

    return 0;
}