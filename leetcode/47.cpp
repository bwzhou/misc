class Solution {
public:
    void gen(int start, vector<int> &num, vector<vector<int>> &result) {
        if (start == num.size()) {
            result.push_back(num);
            return;
        }
        set<int> used;
        for (int i = start; i < num.size(); ++i) {
            // Just check if num[i] != num[start] is not enough because
            // num[i] may equal to num[j] for j > i > start.
            if (used.find(num[i]) == used.end()) {
                swap(num[i], num[start]);
                gen(start + 1, num, result);
                swap(num[i], num[start]);
                used.insert(num[i]);
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> result;
        gen(0, num, result);
        return result;
    }
};