class Solution {
public:
/*
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
*/
    bool isPalindrome(string s) {
        int l = 0;
        int h = s.size() - 1;
        while (l < h) {
            if (isalnum(s[l]) && isalnum(s[h])) {
                if (tolower(s[l]) == tolower(s[h])) {
                    ++l;
                    --h;
                } else {
                    break;
                }
            } else {
                if (!isalnum(s[l])) {
                    ++l;
                }
                if (!isalnum(s[h])) {
                    --h;
                }
            }
        }
        return l >= h;
    }
};
