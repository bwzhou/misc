class Solution {
public:
/*
    void minPathSum(vector<vector<int>> &triangle, int row, int col, int sum, int &minSum) {
        sum += triangle[row][col];
        if (row == triangle.size() - 1) {
            minSum = min(minSum, sum);
            return;
        }
        minPathSum(triangle, row + 1, col, sum, minSum);
        minPathSum(triangle, row + 1, col + 1, sum, minSum);
    }
    int minimumTotal(vector<vector<int> > &triangle) {
        int minSum = INT_MAX;
        int runningSum = 0;
        minPathSum(triangle, 0, 0, runningSum, minSum);
        return minSum;
    }
*/
    int minimumTotal(vector<vector<int> > &t) {
        int n = t.size();
        vector<int> p (n+1, 0);
        while(n-- > 0)
            for(int i = 0; i <= n; ++i) 
                p[i] = t[n][i] + ((p[i] < p[i+1])? p[i] : p[i+1]);
        return p[0];
    }
};