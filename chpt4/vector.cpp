#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    vector<double> temps;
    for(double temp; cin >> temp;) {    // read into temp
        temps.push_back(temp);          // put temp into temps
    }

    // compute the mean temperature
    double sum = 0;
    for(double x : temps) sum += x; // similar to for(double x = temps.begin(); x != temps.end(); ++x)
    cout << "Average temperature: " << sum / temps.size() << '\n';

    // compute the median temperature
    sort(temps.begin(), temps.end());
    cout << "Median temperature: " << temps[temps.size()/2] << '\n';
}
