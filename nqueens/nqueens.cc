#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
bool isValid(int row, int col, vector<int> &queens) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || abs(row - i) == abs(col - queens[i])) {
            return false;
        }
    }
    return true;
}
void solve(int row, vector<int> &queens, vector<vector<string>> &result) {
    if (row == queens.size()) {
        vector<string> solution(queens.size(), string(queens.size(), '.'));
        for (int i = 0; i < queens.size(); ++i) {
            solution[i][queens[i]] = 'Q';
        }
        result.push_back(solution);
        return;
    }
    for (int col = 0; col < queens.size(); ++col) {
        if (isValid(row, col, queens)) {
            queens[row] = col;
            solve(row + 1, queens, result);
        }
    }
}
vector<vector<string> > solveNQueens(int n) {
    vector<vector<string>> result;
    vector<int> queens(n, 0);
    solve(0, queens, result);
    return result;
}
int main(int argc, char** argv) {
  for (auto &each : solveNQueens(atoi(argv[1]))) {
    for (auto &row : each) {
      cout << row << endl;
    }
    cout << endl;
  }
}
