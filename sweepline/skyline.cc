// Skyline
// Input:
// an array of of buildings represented in tuples of (x, y, begin/end, id)
// Output: 
// an array of points that define the collective profile of all the buildings

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <cstdlib>
#include <set>

using namespace std;

struct Point {
  int x;
  int y;
  bool isBegin;
  int id;
  Point(int _x, int _y, bool _isBegin, int _id) :
    x(_x), y(_y), isBegin(_isBegin), id(_id) {}
  bool operator<(const Point &rhs) const {
    return x < rhs.x;
  }
};

vector<pair<int, int>> skyline(vector<Point> &B) {
  vector<pair<int, int>> R;
  if (B.empty()) return R;
  map<int, set<int>> C;
  int lastX = B[0].x;
  int before = 0;
  for (int i = 0; i <= B.size(); ++i) {
    Point &each = B[i];
    if (each.x != lastX || i == B.size()) {
      int after = C.empty() ? 0 : C.rbegin()->first;
      if (before != after) {
        cout << "x:" << lastX << " y:" << before << "->" << after << endl;
        R.push_back(make_pair(lastX, before));
        R.push_back(make_pair(lastX, after));
      }
      if (i == B.size()) break;
      before = after;
      lastX = each.x;
    }
    if (each.isBegin) {
      C[each.y].insert(each.id);
    } else {
      C[each.y].erase(each.id);
      if (C[each.y].empty()) {
        C.erase(each.y);
      }
    }
  }
  return R;
}

// argv[1]: number of points
// argv[2]: max of x and y
int main(int argc, char **argv) {
  vector<Point> B;
  default_random_engine gen((random_device())());
  uniform_int_distribution<int> dis(1, atoi(argv[2]));
  for (int i = 0; i < atoi(argv[1]); ++i) {
    int x1 = dis(gen);
    int x2 = dis(gen);
    int y = dis(gen);
    B.push_back(Point(min(x1, x2), y, true, i));
    B.push_back(Point(max(x1, x2), y, false, i));
  }
  sort(B.begin(), B.end());
  for (auto &each : B) {
    cout << each.x << "," << each.y << "," << (each.isBegin ? 'b' : 'e')
         << "," << each.id << endl;
  }
  for (auto &each : skyline(B)) {
    cout << each.first << "," << each.second << endl;
  }
  return 0;
}
