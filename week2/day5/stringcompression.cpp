#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    int write = 0; // position to write compressed chars
    int read = 0;  // position to read chars

    while (read < n) {
        char curr = chars[read];
        int count = 0;

        while (read < n && chars[read] == curr) {
            read++;
            count++;
        }

        chars[write++] = curr;

        if (count > 1) {
            string cnt = to_string(count);

            for (char c : cnt) {
                chars[write++] = c;
            }
        }
    }

    return write;
}

int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};

    int len = compress(chars);

    cout << "Length = " << len << endl;
    cout << "Compressed: ";

    for (int i = 0; i < len; i++) {
        cout << chars[i] << " ";
    }

    return 0;
}