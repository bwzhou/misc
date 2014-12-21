class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n) {
            if (n % 26) {
                result = (char) (n % 26 - 1 + 'A') + result;
            } else {
                result = 'Z' + result;
                n -= 26;
            }
            n /= 26;
        }
        return result;
    }
};
