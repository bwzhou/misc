class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int size = n;
        int i = 0;
        while (i < size) {
            if (A[i] == elem) {
                swap(A[i], A[size - 1]);
                --size;
            } else {
                ++i;
            }
        }
        return size;
    }
};