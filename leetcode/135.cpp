class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.size() == 1) {
            return 1;
        }
        vector<int> candy(ratings.size(), 0);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                if (candy[i-1] == 0) candy[i-1] = 1;
                candy[i] = candy[i-1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                if (candy[i+1] == 0) candy[i+1] = 1;
                candy[i] = max(candy[i+1] + 1, candy[i]);
            }
        }
        int sum = 0;
        for (int i = 0; i < candy.size(); ++i) {
            sum += candy[i] ? candy[i] : 1;
        }
        return sum;
    }
};