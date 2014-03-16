class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pathNum(n + 1, 0);
        pathNum[1] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pathNum[j + 1] += pathNum[j];
            }
        }
        return pathNum[n];
    }
};