#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix.pop_back();

            if (prefix.empty()) {
                return "";
            }
        }
    }

    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};

    cout << longestCommonPrefix(strs) << endl;

    return 0;
}