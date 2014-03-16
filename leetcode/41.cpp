class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; ++i) {
            while (A[i] != i + 1 && A[i] >= 1 && A[i] <= n && A[A[i] - 1] != A[i]) {
                swap(A[A[i] - 1], A[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (A[i] != i + 1) {
                return i + 1;
            }
       }
       return n + 1;
    }
};