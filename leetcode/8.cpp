class Solution {
public:
    int atoi(const char *str) {
        bool neg = false;
        char *p = (char *) str;
        while (*p && *p == ' ') { ++p; }
        if (*p == '\0') { return 0; }
        if (*p == '+') { ++p; }
        else if (*p == '-') { neg = true; ++p; }
        if (*p == 0 || *p < '0' || *p > '9') { return 0; }
        int v = 0;
        while (*p && *p >= '0' && *p <= '9') {
            // overflow detection should be done aforehand
            // INT_MAX%10 == 7
            // INT_MIN%10 == -8
            if (!neg && (v > INT_MAX/10 || v == INT_MAX/10 && *p - '0' > 7)) { return INT_MAX; }
            if (neg && (v < INT_MIN/10 || v == INT_MIN/10 && *p - '0' > 8)) { return INT_MIN; }
            v *= 10;
            v += neg ? '0' - *p : *p - '0';
            ++p;
        }
        return v;
    }
};