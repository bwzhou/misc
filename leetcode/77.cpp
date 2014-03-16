class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
        if (n == 0) {
            return result;
        }
        if (k == 0) {
            result.push_back(vector<int>());
            return result;
        }
        if (n == k) {
            vector<int> s(n, 0);
            iota(s.begin(), s.end(), 1);
            result.push_back(s);
            return result;
        }
        for (auto each : combine(n - 1, k)) {
            result.push_back(each);
        }
        for (auto each : combine(n - 1, k - 1)) {
            each.push_back(n);
            result.push_back(each);
        }
        return result;
    }
};