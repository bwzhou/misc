class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        set<int> slots;
        for (const auto &each : num) {
            slots.insert(each);
        }
        int len = 0;
        int maxLen = 0;
        int prev;
        for (set<int>::iterator it = slots.begin(), ie = slots.end(); it != ie; ++it) {
            if (it == slots.begin()) {
                len = 1;
            } else {
                if (*it == prev + 1) {
                    ++len;
                } else {
                    len = 1;
                }
            }
            maxLen = max(maxLen, len);
            prev = *it;
        }
        return maxLen;
    }
};