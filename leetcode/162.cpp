class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int l = 0;
        int h = num.size() - 1;
        while (l < h - 1) {
            int m = l + (h - l) / 2;
            if (num[m - 1] < num[m] && num[m] > num[m + 1]) {
                return m;
            } else {
                if (num[m - 1] > num[m]) {
                    h = m;
                } else {
                    l = m;
                }
            }
        }
        return num[l] < num[h] ? h : l;
    }
};
