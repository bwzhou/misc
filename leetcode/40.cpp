class Solution {
public:
    void solve(vector<int> &num, int start, int target, vector<int> &solution, vector<vector<int>> &result) {
        if (target == 0) {
            result.push_back(solution);
            return;
        }
        if (start == num.size() || target < 0) {
            return;
        }
        int end = start;
        while (end < num.size() && num[start] == num[end]) {
            ++end;
        }
        solve(num, end, target, solution, result);
        for (int i = start; i < end; ++i) {
            solution.push_back(num[start]);
            target -= num[start];
            solve(num, end, target, solution, result);
        }
        for (int i = start; i < end; ++i) {
            solution.pop_back();
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> result;
        vector<int> solution;
        sort(num.begin(), num.end());
        solve(num, 0, target, solution, result);
        return result;
    }
};