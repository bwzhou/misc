class Solution {
public:
/*
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
                maxLen = max(maxLen, len);
            } else {
                if (*it == prev + 1) {
                    ++len;
                    maxLen = max(maxLen, len);
                } else {
                    len = 1;
                }
            }
            prev = *it;
        }
        return maxLen;
    }
*/
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> count;
        int maxConsec = 0;
        for (auto &each : num) {
            if (count[each]) {
                continue;
            }
            count[each] = 1;
            int left{count[each - 1]};
            int right{count[each + 1]};
            count[each - left] = count[each + right] = 1 + left + right; ////
            maxConsec = max(maxConsec, 1 + left + right);
        }
        return maxConsec;
    }
};
