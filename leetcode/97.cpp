class Solution {
public:
/*
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        vector<bool> result(s1.size() + 1, false);
        result[0] = true;
        bool last1 = false, last2;
        for (int i = 1; i <= s3.size(); ++i) { // i is the size of s3
            for (int j = 0; j <= i && j <= s1.size(); ++j) { // j is the size of s1
                last2 = last1; // old result[j - 1]
                last1 = result[j]; // old result[j]
                result[j] = (j > 0 && last2 && s1[j - 1] == s3[i - 1]) ||
                            (j < i && last1 && s2[i - j - 1] == s3[i - 1]);
            }
        }
        return result[s1.size()];
    }
*/
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        vector<bool> result(s1.size(), false);
        for (int i = 0; i <= s2.size(); ++i) {
            for (int j = 0; j <= s1.size(); ++j) {
                result[j] = (i > 0 && result[j] && s2[i - 1] == s3[i + j - 1]) ||
                            (j > 0 && result[j - 1] && s1[j - 1] == s3[i + j - 1]) ||
                            (i == 0 && j == 0);
            }
        }
        return result[s1.size()];
    }
};
