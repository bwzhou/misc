class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> result;
        deque<vector<int>> worklist;
        worklist.push_back(vector<int>());
        while (!worklist.empty()) {
            vector<int> top = worklist.front();
            worklist.pop_front();
            for (auto &each : S) {
                if (top.empty() || each > top.back()) {
                    top.push_back(each);
                    worklist.push_back(top);
                    top.pop_back();
                }
            }
            result.push_back(top);
        }
        return result;
    }
};