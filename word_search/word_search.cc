#include <iostream>
#include <vector>
using namespace std;
bool check(vector<vector<char>> &board, int i, int j, vector<vector<bool>> &visited, string word, int start) {
    if (board[i][j] == word[start]) {
        cout << word[start] << endl;
        visited[i][j] = true;
        if (start == word.size() - 1) {
            return true;
        } else {
            if ((i - 1 >= 0 && !visited[i - 1][j] && check(board, i - 1, j, visited, word, start + 1)) ||
                   (j - 1 >= 0 && !visited[i][j - 1] && check(board, i, j - 1, visited, word, start + 1)) ||
                   (j + 1 < visited[0].size() && !visited[i][j + 1] && check(board, i, j + 1, visited, word, start + 1)) ||
                   (i + 1 < visited.size() && !visited[i + 1][j] && check(board, i + 1, j, visited, word, start + 1))) {
              return true;
            } else {
              visited[i][j] = false;
              return false;
        }
    }
    return false;
}
bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j] == word[0]) {
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
                if (check(board, i, j, visited, word, 0)) {
                    return true;
                }
            }
        }
    }
    return false;
}
int main() {
  vector<vector<char>> board = { {'a', 'b', 'c', 'e'}, {'s', 'f', 'e', 's'}, {'a', 'd', 'e', 'e'} };
  string word = "abceseeefs";
  cout << exist(board, word) << endl;
}
