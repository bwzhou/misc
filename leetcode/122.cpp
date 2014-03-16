class Solution {
public:
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
};