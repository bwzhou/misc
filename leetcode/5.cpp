class Solution {
public:
    pair<int, int> getPalindrome(string s, int i, int j) {
        while (i >= 0 && j < s.size()) {
            if (s[i] != s[j]) {
                break;
            }
            --i;
            ++j;
        }
        return make_pair(j - i - 1, i + 1);
    }
    string longestPalindrome(string s) {
        int longest = 0;
        int start = 0;
        pair<int, int> res;
        for (int i = 0; i < s.size(); ++i) { // necessary to consider getPalindrome(n - 1, n - 1) to cover single-char strings
            res = getPalindrome(s, i, i);
            if (res.first > longest) {
                longest = res.first;
                start = res.second;
            }
            res = getPalindrome(s, i, i + 1);
            if (res.first > longest) {
                longest = res.first;
                start = res.second;
            }
        }
        return s.substr(start, longest);
    }
};