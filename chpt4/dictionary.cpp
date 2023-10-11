#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main() {
    vector<string> words;
    for(string temp; cin >> temp; ) {
        words.push_back(temp);
    }

    cout << "Number of words stored: " << words.size() << "\n";

    sort(words.begin(), words.end());

    std::unordered_map<std::string, int> m;
    m["disliked"] = 1;
    m["word"] = 2;
    m["fuck"] = 3;

    for(int i = 0; i < words.size(); ++i) {
        switch(m[words[i]]) {
            case 1:
                if (i == 0 || words[i-1] != words[i]) {
                    cout << "BLEEP" << "\n";
                }
                break;
            case 2:
                if (i == 0 || words[i-1] != words[i]) {
                    cout << "BLEEP" << "\n";
                }
                break;
            case 3:
                if (i == 0 || words[i-1] != words[i]) {
                    cout << "BLEEP" << "\n";
                }
                break;
            default:
                if (i == 0 || words[i-1] != words[i]) {
                    cout << words[i] << "\n";
                }
                break;
        }
    }

    return 0;
}