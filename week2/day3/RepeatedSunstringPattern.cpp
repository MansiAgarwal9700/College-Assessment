#include <iostream>
using namespace std;

bool repeatedSubstringPattern(string s) {
    int n = s.size();

    for (int len = 1; len <= n / 2; len++) {
        if (n % len == 0) { // substring length must divide n
            string sub = s.substr(0, len);
            string formed = "";

            int times = n / len;
            for (int i = 0; i < times; i++) {
                formed += sub;
            }

            if (formed == s) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    string s = "abab";
    cout << (repeatedSubstringPattern(s) ? "true" : "false");
    return 0;
}