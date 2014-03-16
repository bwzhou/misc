class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() -  1;
        int j = b.size() - 1;
        int carry = 0;
        char digit;
        string result;
        while (i >= 0 || j >= 0) {
            int ones = 0;
            if (i >= 0 && a[i] == '1') {
                ++ones;
            }
            if (j >= 0 && b[j] == '1') {
                ++ones;
            }
            if (carry == 1) {
                ++ones;
            }
            carry = ones / 2;
            digit = ones % 2 + '0';
            result = digit + result;
            --i;
            --j;
        }
        if (carry == 1) {
            result = '1' + result;
        }
        return result;
    }
};