class Solution {
public:
    void subset(map<int, int> elements, vector<int> curr, vector<vector<int>> &result) {
        if (elements.empty()) {
            result.emplace_back(curr);
            return;
        }
        int num = elements.begin()->first;
        int count = elements.begin()->second;
        elements.erase(num);
        subset(elements, curr, result);
        for (int j = 0; j < count; ++j) {
            curr.emplace_back(num);
            subset(elements, curr, result);
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        map<int, int> elements;
        vector<int> curr;
        vector<vector<int>> result;
        for (auto &each : S) {
            ++elements[each];
        }
        subset(elements, curr, result);
        return result;
    }
};