#include <iostream>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;

    int n = s.size();
    int m = p.size();

    if (m > n) return result;

    vector<int> pCount(26, 0);
    vector<int> windowCount(26, 0);

    for (int i = 0; i < m; i++) {
        pCount[p[i] - 'a']++;
        windowCount[s[i] - 'a']++;
    }

    if (pCount == windowCount) {
        result.push_back(0);
    }

    for (int i = m; i < n; i++) {
        windowCount[s[i] - 'a']++;       // add new char
        windowCount[s[i - m] - 'a']--;   // remove old char

        if (pCount == windowCount) {
            result.push_back(i - m + 1);
        }
    }

    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> ans = findAnagrams(s, p);

    for (int idx : ans) {
        cout << idx << " ";
    }

    return 0;
}