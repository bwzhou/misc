class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') {
            if (*s == '\0') {
                return true;
            } else {
                return false;
            }
        }
        assert(*p != '\0');
        if (p[1] == '*') {
            do {
                if (isMatch(s, p + 2)) {
                    return true;
                }
            } while (*s != '\0' && (*s++ == *p || *p == '.')); // it is necessary to check if *s is '\0' because *p can be '.'
            return false;
        }
        if (*s != '\0' && (*s == *p || *p == '.')) { // ditto
            return isMatch(s + 1, p + 1);
        }
        return false;
    }
};