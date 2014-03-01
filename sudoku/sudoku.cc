#include <iostream>
#include <set>
#include <vector>
using namespace std;
bool solve(vector<string> &board, int curr) {
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
    //cout << "curr:" << curr << endl;
    //cout << "board:" << endl;
    //for (auto &each : board) {
    //  cout << each << endl;
    //}
    //cout << "choices:";
    if (choices.empty()) {
        //cout << "NONE" << endl;
        return false;
    }
    //for (auto each : choices) {
    //  cout << each << " ";
    //}
    //cout << endl;
    for (char each : choices) {
        board[i][j] = each;
        if (solve(board, curr + 1)) {
            return true;
        }
    }
    board[i][j] = '.';
    //cout << "curr:" << curr << " BACKTRACK" << endl;
    return false;
}
void solveSudoku(vector<string> &board) {
    solve(board, 0);
}
int main() {
    vector<string> board{".....7..9",".4..812..","...9...1.","..53...72","293....5.",".....53..","8...23...","7...5..4.","531.7...."}; 
    solveSudoku(board);
    for (auto &each : board) {
      cout << each << endl;
    }
}
