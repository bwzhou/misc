#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxProfit(vector<int> &prices) {
    vector<int> fromLeft;
    vector<int> fromRight;
    int low = INT_MAX;
    int high = 0;
    int maxProfit = 0;
    for (auto &each : prices) {
        low = min(low, each);
        fromLeft.emplace_back(each - low);
    }
    for (int i = prices.size() - 1; i >= 0; --i) {
        high = max(high, prices[i]);
        fromRight.emplace_back(high - prices[i]);
    }
    reverse(fromRight.begin(), fromRight.end());
    // the follow loop executes even when prices is empty because prices.size()
    // is unsigned, hence the casting to int.
    for (int i = 0; i < (int) prices.size() - 1; ++i) {
        cout << i << endl;
        maxProfit = max(maxProfit, fromLeft[i] + fromRight[i + 1]);
    }
    return maxProfit;
}

int main() {
    vector<int> prices;
    cout << maxProfit(prices) << endl;
}
