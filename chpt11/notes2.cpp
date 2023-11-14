#include<iostream>
#include<fstream>
#include<vector>
#include "../std_lib_facilities.h"

double str_to_double(string s);

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

    for (int i = 0; i < 128; i++) {
        of1 << i;
    }

    std::string filename2 = "notes_file2.txt";
    std::ifstream if1 {filename2};  // defaults to iso_base::in

    std::string filename3 = "notes_file3.txt";
    std::ifstream of2 {filename3,std::ios_base::app};   // ofstreams by default include ios_base::out

    std::fstream fs1 {"myfile.txt",std::ios_base::in|std::ios_base::out};    // both in and out

    if (!fs1) {
        // opps: we cannot open that file that way
        // handle error
    }

    of1.close();
    if1.close();
    of2.close();
    fs1.close();

/* HANDLING BINARY FILES EXAMPLE */

    // open an istream for binary input from a file:
    std::cout << "Please enter an input file name\n";
    std::string name;
    std::cin >> name;   
    std::ifstream ifs {name,std::ios_base::binary}; // note: stream mode
        // binary tells the stream not to try anything clever with the bytes
    if (!ifs) { /* HANDLE ERROR HERE */ }

    // open an ostream for binary outputt to a file:
    std::cout << "Please enter output file name\n";
    std::string oname;
    std::cin >> oname;
    std::ofstream ofs {name,std::ios_base::binary}; // note: stream mode
        // binary tells the stream not to try anything clever with the bytes
    if (!ofs) { /* HANDLE ERROR HERE */ }

    vector<int> v;

    // read from binary file
    for (int x; ifs.read(as_bytes(x),sizeof(int)); ) {  // note: reading bytes
        v.push_back(x);
    }

    /* do something with v */

    // write to binary file
    for (int x : v) {
        ofs.write(as_bytes(x),sizeof(int)); // note: writing bytes
    }

    ofs.close();
    ifs.close();
    // return 0;

/* HANDLING POSITIONING IN FILES */

    // there is virtually no run-time error checking when using positioning
    fstream fs2 {filename1};

    if(!fs2) { /* throw some error */ }

    fs2.seekg(5);
    char ch;
    fs2 >> ch;
    /*
        this prints:
        character[5] is 5 (casted: 53) (converted: 5)
    */
    std::cout << "character[5] is " << ch << " (casted: " << (int)ch << ")" << " (converted: " << atoi(&ch) << ")\n"; // char 5 in unicode is 53(decimal)

    fs2.seekp(1);   // move the writing position (p for "put") to 1
    fs2 << 'y';     // write and increment writing position

/* STRING STREAMS EXAMPLE */

    double d1 = str_to_double("12.4");              // testing
    double d2 = str_to_double("1.34e-3");              
    double d3 = str_to_double("twelve point three");// will call error (if it was handled)

    std::cout << d1 << std::setw(10) << d2 << std::setw(4) << d3 << '\n';

/* LINE ORIENTED INPUT */

    std::string name1;
    std::cin >> name1;          // input: Dennis Ritchie
    std::cout << name1 << '\n'; // output: Dennis

    // vs   

    std::string name2;  
    getline(cin,name2);         // input: Dennis Ritchie
    std::cout << name2 << '\n'; // output: Dennis Ritchie

/* CHARACTER CLASSIFICATION */

    // consider: 1 + 4 * x <= y / z * 5
    // sometimes when we read a whole line it can get messy
    // sometimes we need to go down a level of abstraction instead of up

    for (char ch; cin.get(ch); ) {
        if (isspace(ch)) { /* do nothing, e.i. skip */ }
        if (isdigit(ch)) { /* read a number */ }
        else if (isalpha(ch)) { /* read an identifier */ }
        else { /* deal with operation */ }
    }

    /*
        std library char classification functions:
        -isspace(c)
        -isalpha(c)
        -isdigit(c)
        -isxdigit(c)    -> is c a hex digit or hex alpha
        -isupper(c)
        -islower(c)
        -isalnum(c)     -> is c a letter or a decimal digit
        -iscntrl(c)     -> is c a control character (ASCII 0..31 or 127)
        -ispunct(c)
        -isprint(c)     -> is c printable ASCII
        -isgraph(c)     -> is isalpha(), isdigit(), or ispunct()
    */

    
}

/* STRING STREAMS FUNCTION */

    // you can use a string as a source of an istream/ostream
    // istringstream / ostringstream
    
    double str_to_double(string s)
    // if possible: convert characters in s to floating-point value
    {
        istringstream is {s};   // make a stream so that we can read from s
        double d;
        is >> d;
        if (!is) { /* handle error */ }
        return d;
    }