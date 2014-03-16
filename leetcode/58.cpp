class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL) {
            return 0;
        }
        int size = 0;
        bool inWord = false;
        while (*s != '\0') {
            if (isalpha(*s)) {
                if (!inWord) {
                    inWord = true;
                    size = 1;
                } else {
                    ++size;
                }
            } else {
                inWord = false;
            }
            ++s;
        }
        return size;
    }
};