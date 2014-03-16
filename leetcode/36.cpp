class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i) {
            set<char> row;
            set<char> col;
            set<char> block;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.' && row.find(board[i][j]) != row.end()) {
                    return false;
                }
                row.insert(board[i][j]);
                if (board[j][i] != '.' && col.find(board[j][i]) != col.end()) {
                    return false;
                }
                col.insert(board[j][i]);
                if (board[i/3*3 + j/3][i%3*3 + j%3] != '.' && block.find(board[i/3*3 + j/3][i%3*3 + j%3]) != block.end()) {
                    return false;
                }
                block.insert(board[i/3*3 + j/3][i%3*3 + j%3]);
            }
        }
        return true;
    }
};