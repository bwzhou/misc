class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        vector<int> result;
        for (auto it = digits.rbegin(), ie = digits.rend(); it != ie; ++it) {
            int tmp = *it + carry;
            result.push_back(tmp % 10);
            carry = tmp / 10;
        }
        if (carry) {
            result.push_back(carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};