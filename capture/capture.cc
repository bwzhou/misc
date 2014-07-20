#include <vector>
#include <iostream>
using namespace std;
void mark(vector<string> &board, int x, int y) {
    if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 'O') {
        board[x][y] = 'Q';
        mark(board, x + 1, y);
        mark(board, x, y + 1);
        mark(board, x - 1, y);
        mark(board, x, y - 1);
    }
}
void solve(vector<string> &board) {
    int n = (int) board.size();
    if (n == 0) return;
    int m = (int) board[0].size();
    if (m == 0) return;
    for (int i = 0; i < m - 1; ++i)
        mark(board, 0, i);
    for (int i = 0; i < n - 1; ++i)
        mark(board, i, m - 1);
    for (int i = m - 1; i > 0; --i)
        mark(board, n - 1, i);
    for (int i = n - 1; i > 0; --i)
        mark(board, i, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'Q')
                board[i][j] = 'O';
}
int main() {
  vector<string> board{"OXOOXOXOOO","OOOOOXOOXO","OOOOOOOOXO","OOOOOOXXXO","OOOOOXOOOX","OOOOOOOOOX","OOOOXOOOOO","OOOOXOOOXO","XXOOOOOOOO","OOOOXOXOOX"};
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
      cout << board[i][j];
    }
    cout << endl;
  }
  cout << endl;
  solve(board);
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
      cout << board[i][j];
    }
    cout << endl;
  }
}
