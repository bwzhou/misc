class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) {
            return 0;
        }
        vector<int> count(s.size(), 0);
        if (s[0] != '0') {
            ++count[0];
        }
        if (s[1] != '0') {
            count[1] += count[0];
        }
        if (s[0] != '0' && atoi(s.substr(0, 2).c_str()) <= 26) {
            ++count[1];
        }
        for (int i = 2; i < s.size(); ++i) {
            if (s[i] != '0') {
                count[i] += count[i - 1];
            }
            if (s[i - 1] != '0' && atoi(s.substr(i - 1, 2).c_str()) <= 26) {
                count[i] += count[i - 2];
            }
        }
        return count[s.size() - 1];
    }
};