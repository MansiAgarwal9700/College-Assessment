#include <iostream>
#include <stack>
using namespace std;

string decodeString(string s) {
    stack<int> countStack;
    stack<string> stringStack;

    string currString = "";
    int k = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            k = k * 10 + (ch - '0');
        }
        else if (ch == '[') {
            countStack.push(k);
            stringStack.push(currString);

            k = 0;
            currString = "";
        }
        else if (ch == ']') {
            int repeat = countStack.top();
            countStack.pop();

            string temp = stringStack.top();
            stringStack.pop();

            while (repeat--) {
                temp += currString;
            }

            currString = temp;
        }
        else {
            currString += ch;
        }
    }

    return currString;
}

int main() {
    string s = "3[a2[c]]";
    cout << decodeString(s);
    return 0;
}