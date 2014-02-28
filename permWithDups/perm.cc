#include <iostream>
#include <vector>
#include <set>
using namespace std;
void gen(int start, vector<int> num, vector<vector<int>> &result) {
    if (start == num.size()) {
        result.push_back(num);
        return;
    }
    set<int> used;
    for (int i = start; i < num.size(); ++i) {
        if (used.find(num[i]) == used.end()) {
            swap(num[i], num[start]);
            gen(start + 1, num, result);
            swap(num[i], num[start]);
            used.insert(num[i]);
        }
    }
}
vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int>> result;
    gen(0, num, result);
    return result;
}
int main() {
    vector<int> num{1, 1, 2, 2, 3, 3, 3, 4, 5};
    for (auto each : permuteUnique(num)) {
      for (auto i : each) {
        cout << i << " ";
      }
      cout << endl;
    }
}
