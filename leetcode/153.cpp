class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0;
        int h = num.size() - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            // Consider two partitions [l, m] and [m+1, h]:
            // 1. The minimum within a partition must be at either boundary
            // 2. Therefore pursue only the partition with the smaller minimum
            int left = num[l] < num[m] ? num[l] : num[m];
            int right = num[m + 1] < num[h] ? num[m + 1] : num[h];
            if (left < right) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return num[l];
    }
};
