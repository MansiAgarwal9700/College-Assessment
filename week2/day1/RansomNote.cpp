#include <iostream>
#include <vector>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    vector<int> freq(26, 0);

    for (char c : magazine) {
        freq[c - 'a']++;
    }

    for (char c : ransomNote) {
        if (freq[c - 'a'] == 0) {
            return false;
        }
        freq[c - 'a']--;
    }

    return true;
}

int main() {
    string ransomNote = "aa";
    string magazine = "aab";

    cout << (canConstruct(ransomNote, magazine) ? "true" : "false");
    return 0;
}