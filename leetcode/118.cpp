class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) {
            return result;
        }
        result.emplace_back(vector<int>{1});
        for (int i = 1; i < numRows; ++i) {
            vector<int> row;
            for (int j = 0; j <= i; ++j) {
                row.emplace_back((j - 1 >= 0 ? result[i - 1][j - 1] : 0) + (j <= i - 1 ? result[i - 1][j] : 0));
            }
            result.emplace_back(row);
        }
        return result;
    }
};