class Solution {
public:
    void partitionHelper(string &s, int start, map<pair<int, int>, bool> &pal, vector<string> &buf, vector<vector<string>> &result) {
        int n = s.size();
        if (start == n) {
            result.emplace_back(buf);
            return;
        }
        for (int end = start; end < n; ++end) {
            if (pal.find(make_pair(start, end)) == pal.end()) {
                if (start == end ||
                    ((start + 1 == end ||
                      (pal.count(make_pair(start, end)) &&
                       pal[make_pair(start, end)])) &&
                     s[start] == s[end])) {
                    pal[make_pair(start, end)] = true;
                } else {
                    bool isPalindrome = true;
                    for (int l = start, h = end; l < h; ++l, --h) {
                        if (s[l] != s[h]) {
                            isPalindrome = false;
                            break;
                        }
                    }
                    pal[make_pair(start, end)] = isPalindrome;
                }
            }
            if (pal[make_pair(start, end)]) {
                buf.emplace_back(s.substr(start, end - start + 1));
                partitionHelper(s, end + 1, pal, buf, result);
                buf.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        map<pair<int, int>, bool> pal;
        vector<vector<string>> result;
        vector<string> buf;
        partitionHelper(s, 0, pal, buf, result);
        return result;
    }
};