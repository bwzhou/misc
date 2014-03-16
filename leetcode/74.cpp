class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size() * matrix[0].size();
        int l = 0;
        int h = n - 1;
        while (l <= h) {
            int m = (l + h) / 2;
            int row = m / matrix[0].size();
            int col = m % matrix[0].size();
            if (matrix[row][col] < target) {
                l = m + 1;
            } else if (matrix[row][col] > target) {
                h = m - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};