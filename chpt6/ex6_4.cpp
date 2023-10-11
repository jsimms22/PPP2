#include "std_lib_facilities.h"

using namespace std;

class Name_Value {
public:
    string name;
    int age;
};

int main() {
    try {
        Name_Value nameTemp;
        vector<Name_Value> values;

        bool check = true;

        while (check == true) {
            cout << "Enter name and age pairs to be collected, or 'noname' and '0' to end the entry.\n";

            if (cin >> nameTemp.name >> nameTemp.age){
                if (nameTemp.name == "noname" && nameTemp.age == 0) {
                    check = false;
                } else {
                    for (Name_Value element : values) {
                        if (element.name == nameTemp.name) {
                            error("This name already exists: ", nameTemp.name);
                        }
                    }
                    values.push_back(nameTemp);
                }
            } else {
                error("Bad input");
            }
        }
        
        for (Name_Value element : values) {
            cout << "Name: " << element.name << "\tAge: " << element.age << "\n";
        }
    } catch (runtime_error e) {
        cout << e.what() << "\n";
    } catch (...) {
        cout << "Exiting \n";
    }

    return 0;
}   