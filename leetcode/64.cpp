class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<int> pathSum(m + 1, INT_MAX);
        pathSum[1] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pathSum[j + 1] = min(pathSum[j], pathSum[j + 1]) + grid[i][j];
            }
        }
        return pathSum.back();
    }
};