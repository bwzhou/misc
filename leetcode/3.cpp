class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        map<char, int> index;
        int l = 0;
        int s = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (index.find(str[i]) != index.end() && index[str[i]] >= s) {
                l = max(l, i - s);
                s = index[str[i]] + 1;
            }
            index[str[i]] = i;
        }
        l = max(l, (int) str.size() - s);
        return l;
    }
};