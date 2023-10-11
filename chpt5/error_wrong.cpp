#include "std_lib_facilities.h"

using namespace std;

// the "try this" from p.153
int main () {
    string s1 = "ERROR ERROR BEEP BOOP BOP";
    error(s1); //throws an exception with no attempt to catch
}