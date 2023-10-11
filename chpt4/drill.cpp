#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

constexpr double in_to_m = 1.0/39.3701;
constexpr double cm_to_m = 1.0/100.0;
constexpr double ft_to_m = 1.0/3.28084;
const string sum_val = "m"; // strings cannot be used as a constexpr

int main() {
    vector<double> vals;
    
    double new_val;
    string new_unit;

    double large_val, small_val;
    string large_unit, small_unit;

    double temp1, temp2, temp3;
    double sum = 0.0; 
    int i = 0;

    // 
    while(cin >> new_val >> new_unit) {
        if (new_val >= 0.0 && (new_unit == "cm" || new_unit == "m" || new_unit == "in" || new_unit == "ft")) {
            if (i == 0) {
                large_val = new_val; large_unit = new_unit;
                small_val = new_val; small_unit = new_unit;
            }
            //cout << "Loop iteration input: " << new_val << new_unit << "\n";

            temp1 = 0.0;
            if (new_unit != "m") {
                if (new_unit == "in") { temp1 = new_val * in_to_m; }
                else if (new_unit == "ft") { temp1 = new_val * ft_to_m; }
                else if (new_unit == "cm") { temp1 = new_val * cm_to_m; }
            } else { temp1 = new_val; }
            //cout << "temp1 = " << temp1 << "\n";

            temp2 = 0.0;
            if (large_unit != "m") {
                if (large_unit == "in") { temp2 = large_val * in_to_m; }
                else if (large_unit == "ft") { temp2 = large_val * ft_to_m; }
                else if (large_unit == "cm") { temp2 = large_val * cm_to_m; }
            } else { temp2 = large_val; }
            //cout << "temp2 = " << temp2 << "\n";

            temp3 = 0.0;
            if (small_unit != "m") {
                if (small_unit == "in") { temp3 = small_val * in_to_m; }
                else if (small_unit == "ft") { temp3 = small_val * ft_to_m; }
                else if (small_unit == "cm") { temp3 = small_val * cm_to_m; }
            } else { temp3 = small_val; }
            //cout << "temp3 = " << temp3 << "\n";

            if (temp1 > temp2) {
                cout << "The largest value so far is: " << new_val << new_unit << '\n';
                large_val = new_val;
                large_unit = new_unit;
            }

            if (temp1 < temp3) {
                cout << "The smallest value so far is: " << new_val << new_unit << '\n';
                small_val = new_val;
                small_unit = new_unit;
            }

            sum += temp1;
            vals.push_back(temp1);    
            ++i;   
        }
    }
    sort(vals.begin(), vals.end());
    for(double value : vals) cout << value << sum_val << '\n';
}
