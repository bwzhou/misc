class Solution {
public:
/*
    bool isMatch(const char *s, const char *p) {
        if (*p == '*') {
            while (*++p == '*');
            if (*p == '\0') {
                return true;
            }
            while (*s != '\0') {
                if (isMatch(s, p)) {
                    return true;
                }
                ++s;
            }
            return false;
        } else if (*s != '\0' && (*p == '?' || *p == *s)) {
            while (*s != '\0' && (*p == '?' || *p == *s)) {
                ++s;
                ++p;
            }
            return isMatch(s, p);
        } else if (*p == '\0' && *s == '\0') {
            return true;
        } else {
            return false;
        }
    }
*/
    bool isMatch(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s;
        while (*s){
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
            if (*p=='*'){star=p++; ss=s;continue;}
            if (star){ p=star+1; s=++ss;continue;} // backtrack to the last star when there is no match.
            return false;
        }
        while (*p=='*'){p++;}
        return !*p;
    }
};