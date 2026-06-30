#include <iostream>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();

    if (n1 > n2) return false;

    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);

    for (int i = 0; i < n1; i++) {
        freq1[s1[i] - 'a']++;
        freq2[s2[i] - 'a']++;
    }

    if (freq1 == freq2) return true;

    for (int i = n1; i < n2; i++) {
        freq2[s2[i] - 'a']++;           // add new character
        freq2[s2[i - n1] - 'a']--;      // remove old character

        if (freq1 == freq2) return true;
    }

    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << (checkInclusion(s1, s2) ? "true" : "false");
    return 0;
}