class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        int runningMin = prices[0];
        int runningMax = 0;
        for (auto &each : prices) {
            runningMin = min(each, runningMin);
            runningMax = max(each - runningMin, runningMax);
        }
        return runningMax;
    }
};