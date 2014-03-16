class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int l = num[0] + num[1] + num[2];
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); ++i) {
            int j = i + 1;
            int k = num.size() - 1;
            while (j < k) {
                int s = num[i] + num[j] + num[k];
                if (abs(s - target) < abs(l - target)) {
                    l = s;
                }
                if (s > target) {
                    --k;
                } else if (s < target) {
                    ++j;
                } else {
                    return l;
                }
            }
        }
        return l;
    }
};