#include <iostream>
#include <vector>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    vector<int> freq(26, 0);

    // Count frequency of each character
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Find first character with frequency 1
    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    string s = "leetcode";
    cout << firstUniqChar(s) << endl;
    return 0;
}