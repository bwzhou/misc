class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int k = (m + n) / 2;
        int i = 0;
        int j = 0;
        while (k > 1) {
            int k1 = min(m - i, k/2);
            int k2 = min(n - j, k - k1);
            if (k1 == 0) {
                j += k - 1;
                break;
            }
            if (k2 == 0) {
                i += k - 1;
                break;
            }
            if (A[i + k1 - 1] > B[j + k2 - 1]) {
                j += k2;
                k -= k2;
            } else {
                i += k1;
                k -= k1;
            }
        }
        vector<int> gangOfFour;
        if (i < m) gangOfFour.push_back(A[i]);
        if (i + 1 < m) gangOfFour.push_back(A[i + 1]);
        if (j < n) gangOfFour.push_back(B[j]);
        if (j + 1 < n) gangOfFour.push_back(B[j + 1]);
        sort(gangOfFour.begin(), gangOfFour.end());
        if ((m + n) % 2 == 0) {
            return (gangOfFour[0] + gangOfFour[1]) / 2.0;
        } else {
            return (gangOfFour.size() > 1 ? gangOfFour[1] : gangOfFour[0]) * 1.0;
        }
    }
};