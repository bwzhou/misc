class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        if (divisor == 0) {
            return result;
        }
        long long a = abs((double)dividend); // abs(double) to handle -2147483648
        long long b = abs((double)divisor);
        while (a >= b) {
            long long c = b;
            int n = 1;
            while (a >= c) {
                a -= c;
                result += n;
                c <<= 1;
                n <<= 1;
            }
        }
        return (dividend ^ divisor) >> 31 ? -result : result; // (dividend ^ divisor) >> 31 to get the sign bit
    }
};