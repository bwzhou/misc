class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        string res;
        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < (int) s.size() - i; j += (nRows - 1) * 2) { // size() is unsigned
                res += s[i + j];
                if (i != 0 && i != nRows - 1 && i + j + (nRows - 1 - i) * 2 < s.size()) {
                    res += s[i + j + (nRows - 1 - i) * 2];
                }
            }
        }
        return res;
    }
};