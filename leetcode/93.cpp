class Solution {
public:
    bool check(string segment) {
        return !segment.empty() && (segment == "0" || (segment[0] != '0' && atoi(segment.c_str()) < 256));
    }
    void combinations(string s, int start, int dots, string buf, vector<string> &result) {
        if (dots == 0) {
            string residual = s.substr(start);
            if (check(residual)) {
                result.emplace_back(buf + s.substr(start));
            }
            return;
        }
        if (start == s.size()) {
            return;
        }
        for (int size = 1; size <= 3 && start + size - 1 < s.size(); ++size) {
            string segment = s.substr(start, size);
            if (check(segment)) {
                combinations(s, start + size, dots - 1, buf + segment + ".", result);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        combinations(s, 0, 3, "", result);
        return result;
    }
};