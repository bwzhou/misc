class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        vector<bool> result;
        result.push_back(true);
        bool prev;
        for (int i = 1; i <= s3.size(); ++i) { // i is the size of s3
            for (int j = 0; j <= i && j <= s1.size(); ++j) { // j is the size of s1
                if (j == 0) {
                    prev = result[0];
                    result[j] = result[j] && s2[i - j - 1] == s3[i - 1];
                } else if (j == i) {
                    result.push_back(prev && s1[j - 1] == s3[i - 1]);
                } else {
                    bool tmp = prev; // old result[j - 1]
                    prev = result[j]; // old result[j]
                    result[j] = (tmp && s1[j - 1] == s3[i - 1]) || (result[j] && s2[i - j - 1] == s3[i - 1]);
                }
            }
        }
        return result[s1.size()];
    }
};