class Solution {
public:
    void reverseString(string &s, int l, int r) {
        while (l < r) {
            swap(s[l], s[r]);
            ++l;
            --r;
        }
    }
    void reverseWords(string &s) {
        reverseString(s, 0, s.size() - 1);
        int i = 0;
        int begin = -1; // the first char of a word
        int last = 0; // the first index to fill in the current word
        while (i <= s.size()) {
            if (i == s.size() || s[i] == ' ') {
                if (begin >= 0) {
                    reverseString(s, last, i - 1);
                    last += i - begin + 1;
                    begin = -1;
                }
            } else {
                if (begin < 0) {
                    begin = i;
                }
            }
            ++i;
        }
        s.resize(min((int) s.size(), max(0, last - 1))); // max(0, last - 1) to handle empty string
    }
};