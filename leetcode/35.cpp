class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0;
        int h = n - 1;
        while (l <= h) {
            int mid = (h - l) / 2 + l;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return l;
    }
};