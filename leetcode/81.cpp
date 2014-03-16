class Solution {
public:
    bool search(int A[], int n, int target) {
        if (target == A[0] || target == A[n - 1]) {
            return true;
        }
        int low = 0, high = n - 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (A[low] < A[mid] || A[mid] > A[high]) {
                low = mid;
            } else if (A[low] > A[mid] || A[mid] < A[high]) {
                high = mid;
            } else {
                ++low;
            }
        } // after this loop: low = high - 1 && A[low] > A[high]
        if (target > A[0]) {
            high = low;
            low = 0;
        } else {
            low = high;
            high = n - 1;
        }
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == target) {
                return true;
            } else if (A[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};