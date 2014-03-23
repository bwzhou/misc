class Solution {
public:
/*
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int start = 0;
        int end = 0;
        while (end < prices.size()) {
            while (end + 1 < prices.size() && prices[end + 1] <= prices[end]) {
                ++end;
            }
            start = end;
            while (end + 1 < prices.size() && prices[end + 1] > prices[end]) {
                ++end;
            }
            profit += prices[end] - prices[start];
            ++end;
        }
        return profit;
    }
*/
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int buy = 0;
        int sell = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < prices[i - 1]) {
                profit += prices[sell] - prices[buy];
                buy = sell = i;
            } else if (prices[i] >= prices[i - 1]) {
                sell = i;
                if (i == prices.size() - 1) {
                    profit += prices[sell] - prices[buy];
                }
            }
        }
        return profit;
    }
};
