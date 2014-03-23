class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int runningMin = INT_MAX;
        int runningMax = 0;
        for (auto &each : prices) {
            runningMin = min(each, runningMin);
            runningMax = max(each - runningMin, runningMax);
        }
        return runningMax;
    }
};
