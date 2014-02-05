#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;
int longestConsecutive(vector<int> &num) {
    set<int> slots;
    for (const auto &each : num) {
        slots.insert(each);
    }
    int len = 0;
    int maxLen = 0;
    int prev;
    for (set<int>::iterator it = slots.begin(), ie = slots.end(); it != ie; ++it) {
        if (it == slots.begin()) {
            len = 1;
        } else {
            if (*it == prev + 1) {
                ++len;
            } else {
                len = 1;
            }
        }
        maxLen = max(maxLen, len);
        prev = *it;
    }
    return maxLen;
}

int main(int argc, char **argv) {
  vector<int> A = {9,1,4,7,3,-1,0,5,8,-1,6};
  // default_random_engine gen;
  // uniform_int_distribution<int> dis(-atoi(argv[1]), atoi(argv[1]));
  // for (int i = 0; i < atoi(argv[2]); ++i) {
  //   A.push_back(dis(gen));
  // }
  cout << longestConsecutive(A) << endl;
  return 0;
}
