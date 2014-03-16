class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) { // O(N^3) solution. It can be solved in O(N^2) by a O(N^2) hash table
        sort(num.begin(), num.end());
        vector<vector<int>> result;
        for (int i = 0; i < num.size(); ++i) {
            if (i == 0 || num[i] != num[i - 1]) {
                for (int j = i + 1; j < num.size(); ++j) {
                    if (j == i + 1 || num[j] != num[j - 1]) {
                        int k = j + 1;
                        int l = num.size() - 1;
                        while (k < l) {
                            int sum = num[i] + num[j] + num[k] + num[l];
                            if (k > j + 1 && num[k - 1] == num[k] || sum < target) {
                                ++k;
                            } else if (l < num.size() - 1 && num[l + 1] == num[l] || sum > target) {
                                --l;
                            } else {
                                result.push_back({num[i], num[j], num[k], num[l]});
                                ++k;
                                --l;
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};