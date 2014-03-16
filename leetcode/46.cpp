class Solution {
public:
    void gen(int i, vector<int> num, vector<vector<int>> &result) {
        if (i == num.size()) {
            result.push_back(num);
            return;
        }
        for (int j = i; j < num.size(); ++j) {
            swap(num[j], num[i]);
            gen(i + 1, num, result);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> result;
        gen(0, num, result);
        return result;
    }
};