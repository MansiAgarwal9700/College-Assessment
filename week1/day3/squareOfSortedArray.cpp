#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);

    int left = 0, right = n - 1;
    int pos = n - 1;

    while (left <= right) {
        int leftSq = nums[left] * nums[left];
        int rightSq = nums[right] * nums[right];

        if (leftSq > rightSq) {
            result[pos] = leftSq;
            left++;
        } else {
            result[pos] = rightSq;
            right--;
        }
        pos--;
    }

    return result;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> ans = sortedSquares(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}