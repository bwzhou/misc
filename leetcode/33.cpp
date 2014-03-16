class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, h = n - 1;
        int m;
        while (l <= h) {
            m = (l + h) / 2;
            if (A[m] <= A[n - 1]) {
                h = m - 1;
            } else if (A[m] >= A[0]) {
                l = m + 1;
            } else {
                break;
            }
        }
        int offset = l;
        l = 0;
        h = n - 1;
        while (l <= h) {
            m = (l + h) / 2;
            if (A[(m + offset) % n] < target) {
                l = m + 1;
            } else if (A[(m + offset) % n] > target) {
                h = m - 1;
            } else {
                return (m + offset) % n;
            }
        }
        return -1;
    }
};