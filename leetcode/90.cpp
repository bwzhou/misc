class Solution {
public:
/*
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
*/
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        sort(S.begin(), S.end()); // sort so duplicated numbers stay consecutive
        int offset = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (i > 0 && S[i] != S[i - 1]) { // the first appearance of a number get appended to all previous subsets while dups are only appended to the last level of subsets to prevent redundant subsets.
                offset = 0;
            }
            vector<vector<int>> curr;
            for (int j = offset; j < result.size(); ++j) {
                vector<int> each(result[j]);
                each.push_back(S[i]);
                curr.push_back(each);
            }
            offset = result.size();
            result.insert(result.end(), curr.begin(), curr.end());
        }
        return result;
    }
};
