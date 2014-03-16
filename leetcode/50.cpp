class Solution {
public:
    double pow(double x, int n) {
        double result = 1;
        bool sign = n < 0;
        n = abs(n) & 0x7fffffff; // abs(-2147483648) == -2147483648
        while (n) {
            if (n & 1) {
                result *= x;
            }
            n >>= 1;
            x *= x;
        }
        return sign ? 1/result : result;
    }
};