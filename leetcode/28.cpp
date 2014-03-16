class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL) {
            return NULL;
        }
        if (*needle == '\0') {
            return haystack;
        }
        char *h = haystack;
        char *n = needle;
        while (*++n) { // we know needle is not empty due to the above check
            ++h;
        } // h points to the strlen(needle)-th character in haystack
        while (*h != '\0') {
            char *t = haystack;
            char *p = needle;
            while (*p != '\0') {
                if (*p != *t) {
                    break;
                }
                ++p;
                ++t;
            }
            if (*p == '\0') {
                return haystack;
            }
            ++haystack;
            ++h;
        }
        return NULL;
    }
};