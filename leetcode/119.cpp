class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> row(2, vector<int>(rowIndex + 1, 0));
        row[0][0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            row[i % 2][0] = 1;
            for (int j = 1; j <= i; ++j) {
                row[i % 2][j] = row[(i % 2) ^ 1][j - 1] + row[(i % 2) ^ 1][j];
            }
        }
        return row[rowIndex % 2];
    }
};