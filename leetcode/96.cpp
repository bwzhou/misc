class Solution {
public:
    int numTrees(int n) {
        vector<int> unique;
        unique.push_back(1);
        for (int i = 1; i <= n; ++i) {
            int sum = 0;
            for (int j = 0; j < i; ++j) {
                sum += unique[j] * unique[i - 1 - j];
            }
            unique.push_back(sum);
        }
        return unique[n];
    }
};