int minCut(string s) {
    const int n = s.size();
    int cost[n][n];
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            cost[i][j] = len - 1;
            for (int k = i; k < j; ++k) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k + 1][j]);
            }
            if ((i + 1 > j - 1 || cost[i + 1][j - 1] == 0) && s[i] == s[j]) {
                cost[i][j] = 0;
            }
        }
    }
    return cost[0][n - 1];
}
