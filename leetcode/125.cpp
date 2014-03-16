class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, h = s.size() - 1;
        while (l < h) {
            while (isalnum(s[l]) == false && l < s.size()) {
                ++l;
            }
            while (isalnum(s[h]) == false && h >= 0) {
                --h;
            }
            if (l >= h || tolower(s[l]) != tolower(s[h])) {
                break;
            }
            ++l;
            --h;
        }
        if (l >= h) {
            return true;
        } else {
            return false;
        }
    }
};