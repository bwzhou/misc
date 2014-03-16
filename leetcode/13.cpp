class Solution {
public:
    int valueOf(char c) {
        switch (c) {
            case 'M': return 1000;
            case 'D': return 500;
            case 'C': return 100;
            case 'L': return 50;
            case 'X': return 10;
            case 'V': return 5;
            case 'I': return 1;
            default: return 0;
        }
    }
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i < s.size() - 1 && valueOf(s[i]) < valueOf(s[i + 1])) {
                result += valueOf(s[i + 1]) - valueOf(s[i]);
                ++i;
            } else {
                result += valueOf(s[i]);
            }
        }
        return result;
    }
};