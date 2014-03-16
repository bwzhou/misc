class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int i;
        for (i = 0; i < min(m, n) / 2; ++i) {
            for (int j = i; j < n - 1 - i; ++j) {
                result.push_back(matrix[i][j]);
            }
            for (int j = i; j < m - 1 - i; ++j) {
                result.push_back(matrix[j][n - 1 - i]);
            }
            for (int j = n - 1 - i; j > i; --j) {
                result.push_back(matrix[m - 1 - i][j]);
            }
            for (int j = m - 1 - i; j > i; --j) {
                result.push_back(matrix[j][i]);
            }
        }
        if (min(m, n) % 2) {
            if (m <= n) {
                for (int j = i; j < n - i; ++j) {
                    result.push_back(matrix[i][j]);
                }
            } else {
                for (int j = i; j < m - i; ++j) {
                    result.push_back(matrix[j][i]);
                }
            }
        }
        return result;
    }
};