class Solution {
public:
    void gen(int n, int l, int r, string curr, vector<string> &result) {
        if (l == n && r == n) {
            result.push_back(curr);
            return;
        }
        if (r > l || l > n || r > n) {
            return;
        }
        gen(n, l + 1, r, curr + '(', result);
        if (r < l) {
            gen(n, l, r + 1, curr + ')', result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        gen(n, 0, 0, "", result);
        return result;
    }
};