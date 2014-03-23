class Solution {
public:
/*
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
*/
    vector<int> getRow(int k) {
        vector<int> p(k + 1, 0);
        int tmp1 = 0;
        int tmp2 = 0;
        p[0] = 1;
        for (int i = 1; i <= k; ++i) {
            //tmp1 = 0; // this can be skipped since the last element of each row is initialized to 0
            for (int j = 0; j <= i; ++j) {
                tmp2 = tmp1;
                tmp1 = p[j];
                p[j] += tmp2;
            }
        }
        return p;
    }
};
