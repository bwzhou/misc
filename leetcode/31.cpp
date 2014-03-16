class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int left = -1;
        int right = -1;
        // find the rightmost number which is less than its successor
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] > num[i - 1]) {
                left = i - 1;
            }
        }
        // find the rightmost/smallest number which is greater than the number found above
        for (int i = left + 1; i < num.size(); ++i) {
            if (num[i] > num[left]) {
                right = i;
            }
        }
        // swap the two numbers
        if (left >= 0) {
            swap(num[left], num[right]);
        }
        // reverse all numbers after the first number
        reverse(num.begin() + left + 1, num.end());
    }
};