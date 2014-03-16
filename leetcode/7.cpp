class Solution {
public:
    int reverse(int x) {
        int y = 0;
        long long z = abs((double) x);
        while (z > 0) {
            y *= 10;
            y += z % 10;
            z /= 10;
        }
        return x>>31 ? -y : y;
    }
};