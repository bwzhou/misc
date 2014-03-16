class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> fromLeft;
        vector<int> fromRight;
        int low = INT_MAX;
        int high = 0;
        int maxProfit = 0;
        for (auto &each : prices) {
            low = min(low, each);
            maxProfit = max(maxProfit, each - low);
            fromLeft.emplace_back(maxProfit);
        }
        maxProfit = 0;
        for (int i = prices.size() - 1; i >= 0; --i) {
            high = max(high, prices[i]);
            maxProfit = max(maxProfit, high - prices[i]);
            fromRight.emplace_back(maxProfit);
        }
        reverse(fromRight.begin(), fromRight.end());
        for (int i = 0; i < (int) prices.size() - 1; ++i) {
            maxProfit = max(maxProfit, fromLeft[i] + fromRight[i + 1]);
        }
        return maxProfit;
    }
};