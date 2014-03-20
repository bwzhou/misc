class Solution {
public:
/*
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
*/
    void mark(vector<vector<char>> &board, int x, int y) {
        vector<pair<int, int>> worklist;
        worklist.push_back(make_pair(x, y));
        while (!worklist.empty()) {
            x = worklist.back().first;
            y = worklist.back().second;
            worklist.pop_back();
            iterativeDeepening(board, x, y, 0, worklist);
        }
    }
    void iterativeDeepening(vector<vector<char>> &board, int x, int y, 
                            int depth, vector<pair<int, int>> &worklist) {
        if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 'O') {
            board[x][y] = 'Q';
            if (depth < 10) {
                iterativeDeepening(board, x + 1, y, depth + 1, worklist);
                iterativeDeepening(board, x, y + 1, depth + 1, worklist);
                iterativeDeepening(board, x - 1, y, depth + 1, worklist);
                iterativeDeepening(board, x, y - 1, depth + 1, worklist);
            } else {
                worklist.push_back(make_pair(x + 1, y));
                worklist.push_back(make_pair(x, y + 1));
                worklist.push_back(make_pair(x - 1, y));
                worklist.push_back(make_pair(x, y - 1));

            }
        }
    }
    void solve(vector<vector<char>> &board) {
        int n = (int) board.size();
        if (n <= 2) return;
        int m = (int) board[0].size();
        if (m <= 2) return;
        
        for (int i = 0; i < m - 1; ++i) {
            mark(board, 0, i);
        }
        for (int i = 0; i < n - 1; ++i) {
            mark(board, i, m - 1);
        }
        for (int i = m - 1; i > 0; --i) {
            mark(board, n - 1, i);
        }
        for (int i = n - 1; i > 0; --i) {
            mark(board, i, 0);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'Q') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
