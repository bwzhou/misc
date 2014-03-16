class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int num = 1;
        for (int offset = 0; offset < n/2; ++offset) {
            for (int i = offset; i < n - 1 - offset; ++i) {
                result[offset][i] = num++;
            }
            for (int i = offset; i < n - 1 - offset; ++i) {
                result[i][n - 1 - offset] = num++;
            }
            for (int i = n - 1 - offset; i > offset; --i) {
                result[n - 1 - offset][i] = num++;
            }
            for (int i = n - 1 - offset; i > offset; --i) {
                result[i][offset] = num++;
            }
        }
        if (n % 2) {
            result[n/2][n/2] = n * n;
        }
        return result;
    }
};