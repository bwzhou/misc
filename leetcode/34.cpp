class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lb, ub, l, h;
        l = 0;
        h = n - 1;
        while (l <= h) {
            int mid = (h - l) / 2 + l;
            if (A[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        if (A[l] != target) {
            return vector<int>{-1, -1};
        }
        lb = l;
        l = 0;
        h = n - 1;
        while (l <= h) {
            int mid = (h - l) / 2 + l;
            if (A[mid] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ub = h;
        return vector<int>{lb, ub};
    }
};