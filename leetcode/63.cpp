class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> pathNum(n + 1, 0);
        pathNum[1] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    pathNum[j + 1] += pathNum[j];
                } else {
                    pathNum[j + 1] = 0;
                }
            }
        }
        return pathNum[n];
    }
};