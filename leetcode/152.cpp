class Solution {
public:
    int maxProduct(int A[], int n) {
        int min = A[0]; // min product ended at each i
        int max = A[0]; // max product ended at each i
        int ret = A[0];
        // 1-D dynamic programming
        for (int i = 1; i < n; ++i) {
            int a = A[i] * min;
            int b = A[i] * max;
            min = a < b ? a : b;
            min = A[i] < min ? A[i] : min;
            max = a > b ? a : b;
            max = A[i] > max ? A[i] : max;
            if (ret < max) {
                ret = max;
            }
        }
        return ret;
    }
};
