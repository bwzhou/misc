class Solution {
public:
    bool solve(vector<vector<char>> &board, int curr) {
        int i, j;
        if (curr == 81) {
            return true;
        }
        i = curr / 9;
        j = curr % 9;
        if (board[i][j] != '.') {
            return solve(board, curr + 1);
        }
        set<char> choices{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for (int ii = 0; ii < 9; ++ii) {
            choices.erase(board[ii][j]);
            choices.erase(board[i][ii]);
        }
        for (int ii = 0; ii < 3; ++ii) {
            for (int jj = 0; jj < 3; ++jj) {
                choices.erase(board[i/3*3 + ii][j/3*3 + jj]);
            }
        }
        if (choices.empty()) {
            return false;
        }
        for (char each : choices) {
            board[i][j] = each;
            if (solve(board, curr + 1)) {
                return true;
            }
        }
        board[i][j] = '.';
        return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        solve(board, 0);
    }
};