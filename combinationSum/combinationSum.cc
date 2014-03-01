#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void solve(vector<int> &candidates, int start, int target, vector<int> &solution, vector<vector<int>> &result) {
  if (target == 0) {
    result.push_back(solution);
    return;
  }
  if (start == candidates.size() || target < 0) {
    return;
  }
  int end = start;
  while (end < candidates.size() && candidates[start] == candidates[end]) {
    ++end;
  }
  solve(candidates, end, target, solution, result);
  for (int i = start; i < end; ++i) {
    solution.push_back(candidates[start]);
    target -= candidates[start];
    solve(candidates, end, target, solution, result);
  }
  for (int i = start; i < end; ++i) {
    solution.pop_back();
  }
}
vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
  vector<int> solution;
  vector<vector<int>> result;
  sort(candidates.begin(), candidates.end());
  solve(candidates, 0, target, solution, result);
  return result;
}
int main() {
  vector<int> A{2, 2, 2, 3, 4};
  int target = 7;
  for (auto &each : combinationSum2(A, target)) {
    for (int num : each) {
      cout << num << " ";
    }
    cout << endl;
  }
}
