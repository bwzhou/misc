#include <map>
#include <iostream>
#include <vector>
using namespace std;

void subset(map<int, int> elements, vector<int> curr, vector<vector<int>> &result) {
    cout << &elements << ":" << elements.size() << endl;
    if (elements.empty()) {
        result.emplace_back(curr);
        return;
    }
    int num = elements.begin()->first;
    int count = elements.begin()->second;
    elements.erase(num);
    subset(elements, curr, result);
    for (int j = 0; j < count; ++j) {
        curr.emplace_back(num);
        subset(elements, curr, result);
    }
}
vector<vector<int> > subsetsWithDup(vector<int> &S) {
    map<int, int> elements;
    vector<int> curr;
    vector<vector<int>> result;
    for (auto each : S) {
        ++elements[each];
    }
    subset(elements, curr, result);
    return result;
}

int main() {
  vector<int> S{1, 2};
  for (auto &each : subsetsWithDup(S)) {
    for (auto &num : each) {
      cout << num << " ";
    }
    cout << endl;
  }
}
