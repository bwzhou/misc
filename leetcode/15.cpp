class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); ++i) {
            if (i == 0 || num[i - 1] != num[i]) {
                int j = i + 1;
                int k = num.size() - 1;
                while (j < k) {
                    int sum = num[i] + num[j] + num[k];
                    if (k < num.size() - 1 && num[k + 1] == num[k] || sum > 0) {
                        --k;
                    } else if (j > i + 1 && num[j - 1] == num[j] || sum < 0) { // the second number can be the same with the first number but not with the previous choice of the second number
                        ++j;
                    } else {
                        result.push_back({num[i], num[j], num[k]});
                        ++j;
                        --k;
                    }
                }
            }
        }
        return result;
    }
};