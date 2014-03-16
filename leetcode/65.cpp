class Solution {
public:
    bool isNumber(const char *s) {
        bool hasComma = false;
        bool hasExp = false;
        int segments = 0;
        const char *prev = s;
        const char *curr = s;
        while (*curr != '\0' && *curr == ' ') ++curr;
        if (*curr != '\0' && (*curr == '+' || *curr == '-')) {
            ++curr;
        }
        while (*curr != '\0') {
            prev = curr;
            while (*curr != '\0' && *curr >= '0' && *curr <= '9') ++curr;
            if (curr > prev) {
                ++segments;
            }
            if (*curr == '.') {
                if (hasExp || hasComma) {
                    return false;
                }
                hasComma = true;
                ++curr;
            } else if (*curr == 'E' || *curr == 'e') {
                if (hasExp || segments == 0) {
                    return false;
                }
                hasExp = true;
                segments = 0;
                ++curr;
                if (*curr != '\0' && (*curr == '+' || *curr == '-')) {
                    ++curr;
                }
            } else if (*curr == '\0') {
                return true;
            } else if (*curr == ' ') {
                break;
            } else {
                return false;
            }
        }
        while (*curr != '\0' && *curr == ' ') ++curr;
        if (*curr != '\0') {
            return false;
        }
        if (segments == 0) {
            return false;
        }
        return true;
    }
};