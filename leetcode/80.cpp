class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2) {
            return n;
        }
        int i = 1;
        for (int j = 2; j < n; ++j) {
            if (A[i - 1] != A[j]) {
                A[++i] = A[j];
            }
        }
        return i + 1;
    }
};