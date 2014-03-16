class Solution {
public:
    bool check(vector<vector<char>> &board, int i, int j, set<pair<int, int>> &visited, string word, int start) {
        if (word.empty() || start == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }
        if (visited.find(make_pair(i, j)) == visited.end() && board[i][j] == word[start]) {
            visited.insert(make_pair(i, j));
            if  (check(board, i - 1, j, visited, word, start + 1) ||
                 check(board, i + 1, j, visited, word, start + 1) ||
                 check(board, i, j - 1, visited, word, start + 1) ||
                 check(board, i, j + 1, visited, word, start + 1)) {
                   return true;
            } else {
                   visited.erase(make_pair(i, j));
                   return false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>> &board, string word) {
        set<pair<int, int>> visited;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                visited.clear();
                if (check(board, i, j, visited, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};