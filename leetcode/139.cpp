class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> breakable(s.size() + 1, false);
        breakable[0] = true;
        for (int i = 0; i <= s.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (breakable[j] && dict.count(s.substr(j, i - j))) {
                    breakable[i] = true;
                    break;
                }
            }
        }
        return breakable[s.size()];
    }
};