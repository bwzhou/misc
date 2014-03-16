class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        string sorted1 = s1;
        sort(sorted1.begin(), sorted1.end());
        string sorted2 = s2;
        sort(sorted2.begin(), sorted2.end());
        if (sorted1 != sorted2) {
            return false;
        }
        for (int l = 1; l < s1.size(); ++l) {
            if (isScramble(s1.substr(0, l), s2.substr(0, l)) && isScramble(s1.substr(l), s2.substr(l)) ||
                isScramble(s1.substr(0, l), s2.substr(s2.size() - l)) && isScramble(s1.substr(l), s2.substr(0, s2.size() - l))) {
                    return true;
            }
        }
        return false;
    }
};