class Solution {
public:
    int findMin(vector<int> &num) {
                int l = 0;
        int h = num.size() - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            int left = num[l] < num[m] ? num[l] : num[m];
            int right = num[m + 1] < num[h] ? num[m + 1] : num[h];
            if (left < right) {
                h = m;
            } else if (left > right) {
                l = m + 1;
            } else {
                h = h - 1;
            }
        }
        return num[l];
    }
};
