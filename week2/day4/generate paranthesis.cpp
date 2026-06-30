
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<string>& result, string curr,
                   int open, int close, int n) {

        if (curr.length() == 2 * n) {
            result.push_back(curr);
            return;
        }

        // Add '(' if we still have some left
        if (open < n) {
            backtrack(result, curr + "(", open + 1, close, n);
        }

        // Add ')' only if it won't make the string invalid
        if (close < open) {
            backtrack(result, curr + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> ans = sol.generateParenthesis(3);

    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}