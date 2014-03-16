class Solution {
public:
    bool check(int i, int j, vector<vector<char>> &board, vector<vector<bool>> &liveness) {
        int x = board.size();
        int y = board[0].size();
        return i >= 0 && i < x && j >=0 && j < y && board[i][j] == 'O' && liveness[i][j] == false;
    }
    void solve(vector<vector<char>> &board) {
        if (board.size() <= 2 || board[0].size() <= 2) {
            return;
        }
        int x = board.size();
        int y = board[0].size();
        vector<vector<bool>> liveness;
        for (int i = 0; i < x; ++i) {
            liveness.push_back(vector<bool>(y, false));
        }
        vector<pair<int, int>> worklist;
        for (int i = 0; i < y - 1; ++i) {
            if (board[0][i] == 'O') {
                liveness[0][i] = true;
                worklist.push_back(make_pair(0, i));
            }
            if (board[x - 1][y - 1 - i] == 'O') {
                liveness[x - 1][y - 1 - i] = true;
                worklist.push_back(make_pair(x - 1, y - 1 - i));
            }
        }
        for (int i = 0; i < x - 1; ++i) {
            if (board[i][y - 1] == 'O') {
                liveness[i][y - 1] = true;
                worklist.push_back(make_pair(i, y - 1));
            }
            if (board[x - 1 - i][0] == 'O') {
                liveness[x - 1 - i][0] = true;
                worklist.push_back(make_pair(x - 1 - i, 0));
            }
       } 
        while (!worklist.empty()) {
            int i = worklist.back().first;
            int j = worklist.back().second;
            worklist.pop_back();
            if (check(i - 1, j, board, liveness)) {
                liveness[i - 1][j] = true;
                worklist.push_back(make_pair(i - 1, j));
            }
            if (check(i, j - 1, board, liveness)) {
                liveness[i][j - 1] = true;
                worklist.push_back(make_pair(i, j - 1));
            }
            if (check(i + 1, j, board, liveness)) {
                liveness[i + 1][j] = true;
                worklist.push_back(make_pair(i + 1, j));
            }
            if (check(i, j + 1, board, liveness)) {
                liveness[i][j + 1] = true;
                worklist.push_back(make_pair(i, j + 1));
            }
        }
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (board[i][j] == 'O' && !liveness[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};