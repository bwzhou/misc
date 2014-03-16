class Solution {
public:
    int maxSum(int A[], int start, int end) { //  divide and conquer
        if (end < start) {
            return INT_MIN;
        }
        if (end == start) {
            return A[start];
        }
        int mid = (end - start) / 2 + start;
        int left = maxSum(A, start, mid);
        int right = maxSum(A, mid + 1, end);
        int sum = 0;
        int maxLeft = INT_MIN;
        int maxRight = INT_MIN;
        for (int i = mid; i >= start; --i) {
            sum += A[i];
            maxLeft = max(maxLeft, sum);
        }
        sum = 0;
        for (int i = mid + 1; i <= end; ++i) {
            sum += A[i];
            maxRight = max(maxRight, sum);
        }
        return max(max(maxLeft + maxRight, left), right);
    }
    int maxSubArray(int A[], int n) {
        return maxSum(A, 0, n - 1);
    }
};