class Solution {
public:
/*
    string multiply(string num1, string num2) {
        int carry;
        string result(num1.size() + num2.size(), '0');
        for (int j = num2.size() - 1; j >= 0; --j) {
            carry = 0;
            for (int i = num1.size() - 1; i >= 0; --i) {
                int p = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
                carry = p / 10;
                result[i + j + 1] = p % 10 + '0';
            }
            if (carry) {
                result[j] = carry + '0';
            }
        }
        int zeros = 0;
        while (zeros < result.size() - 1 && result[zeros] == '0') {
            ++zeros;
        }
        return result.substr(zeros);
    }
*/
    string multiply(string num1, string num2) {
        int carry;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string result(num1.size() + num2.size(), '0');
        for (int j = 0; j < num2.size(); ++j) {
            carry = 0;
            for (int i = 0; i < num1.size(); ++i) {
                int p = (num1[i] - '0') * (num2[j] - '0') + (result[i + j] - '0') + carry;
                carry = p / 10;
                result[i + j] = p % 10 + '0';
            }
            if (carry) {
                result[num1.size() + j] = carry + '0';
            }
        }
        int zeros = result.size();
        while (zeros > 1 && result[zeros - 1] == '0') {
            --zeros;
        }
        result = result.substr(0, zeros);
        reverse(result.begin(), result.end());
        return result;
    }
};