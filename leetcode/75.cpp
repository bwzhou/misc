class Solution {
public:
    void sortColors(int A[], int n) {
        int low = 0;
        int mid = 0;
        int high = n - 1;
        while (A[high] > 1) {
            --high;
        }
        while (mid <= high) {
            if (A[mid] < 1) {
                swap(A[mid], A[low]);
                ++low;
                ++mid;
            } else if (A[mid] == 1) {
                ++mid;
            } else if (A[mid] > 1) {
                swap(A[mid], A[high]);
                --high;
            }
        }
    }
};