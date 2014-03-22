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
            int leftbound{count[each - 1]}; // the length of consecutive numbers to the left
            int rightbound{count[each + 1]}; // the length of consecutive numbers to the right
            // Only update the boundary counters to the new concatenative length
            // Inner counters do not matter
            count[each - leftbound] = count[each + rightbound] = 1 + leftbound + rightbound;
            maxConsec = max(maxConsec, 1 + leftbound + rightbound);
        }
        return maxConsec;
    }
};
