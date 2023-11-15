#include<fstream>
#include<cstring>
#include<utility>

bool isvowel(char& ch)
{
    if (isupper(ch)) { ch = tolower(ch); }
    switch(ch) {
        case 'a': case 'e': case 'i':
        case 'o': case 'u': case 'y':
            return true;
        default:
            return false;
    }
}

int main()
{
    /*
        remove vowels from file
    */

    int position = 0;
    std::fstream fs {"text.txt"};
    for (char ch; fs >> ch; position++) {
        if (isvowel(ch)) {
            //fs << ' ';
            char temp;
            fs.seekg(position+1);
            fs >> temp;
            fs.seekp(position);
            fs << temp;
            fs.seekg(position);
        } else { }        
    }
    
    for (std::string str; std::getline(fs,str); ) {

    }


    fs.close();
}