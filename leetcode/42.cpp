class Solution {
public:
    int trap(int A[], int n) {
        vector<int> rain(n, 0);
        int maxHeight = 0;
        for (int i = 0; i < n; ++i) {
            rain[i] = max(maxHeight, A[i]);
            maxHeight = rain[i];
        }
        maxHeight = 0;
        for (int i = n - 1; i >= 0; --i) {
            rain[i] = min(rain[i], max(maxHeight, A[i]));
            maxHeight = max(maxHeight, A[i]);
        }
        int sum = 0;
        for (int i = 1; i < n - 1; ++i) {
            sum += rain[i] - A[i];
        }
        return sum;
    }
};