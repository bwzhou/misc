class Solution {
public:
    void solve(vector<int> &candidates, int start, int target, vector<int> &solution, vector<vector<int>> &result) {
        if (start == candidates.size() || target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(solution);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            solution.push_back(candidates[i]);
            solve(candidates, i, target - candidates[i], solution, result);
            solution.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> solution;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, solution, result);
        return result; // remember to return result
    }
};