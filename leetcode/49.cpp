class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string>> A;
        for (auto &each : strs) {
            string key = each;
            sort(key.begin(), key.end());
            A[key].push_back(each);
        }
        vector<string> result;
        for (auto &each : A) {
            if (each.second.size() > 1) {
                for (auto &str : each.second) {
                    result.push_back(str);
                }
            }
        }
        return result;
    }
};