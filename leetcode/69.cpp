class Solution {
public:
    int sqrt(int x) {
        int l = 1;
        int h = x;
        while (l <= h) {
            int mid = l + (h - l) / 2; // (l+h)/2 triggers integer overflow for large x.
            if (mid < x / mid) { // ditto: mid*mid triggers overflow
                l = mid + 1;
            } else if (mid > x / mid) {
                h = mid - 1;
            } else {
                return mid;
            }
        }
        return h;
    }
};