#include <algorithm>
#include <random>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// sister city is a one-to-one mapping M from [a1 a2 ... an] to [b1 b2 ... bn],
// that is [M(a1) M(a2) ... M(an)] is a permutation of [a1 a2 ... an]. Hence,
// finding max non-crossing bridges is equivalent to finding the longest
// increasing subsequence in [M(a1) M(a2) ... M(an)].
int lis(const vector<int> &M) {
  vector<int> L(M.size(), 1);
  vector<int> P(M.size(), -1);
  for (int i = 0; i < M.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      if (M[i] > M[j] && L[j] + 1 > L[i]) {
        L[i] = L[j] + 1;
        P[i] = j;
      }
    }
  }

  int maxIndex = 0;
  for (int i = 0; i < L.size(); ++i) {
    if (L[i] > L[maxIndex])
      maxIndex = i;
  }

  int last = maxIndex;
  vector<int> res;
  while (last >= 0) {
    res.push_back(last);
    last = P[last];
  }
  copy(res.rbegin(), res.rend(), ostream_iterator<int>(cout, " "));
  cout << endl;

  return L[maxIndex];
}

// See EPI for intuition on this solution
int lis2(vector<int> &M) {
  vector<int> L;
  for (auto &each : M) {
    vector<int>::iterator it = upper_bound(L.begin(), L.end(), each);
    if (it != L.end()) {
      *it = each;
    } else {
      L.push_back(each);
    }
  }
  return L.size();
}

int main(int argc, char **argv) {
  vector<int> M(atoi(argv[1]));
  iota(M.begin(), M.end(), 0);
  random_shuffle(M.begin(), M.end());
  copy(M.begin(), M.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << lis(M) << endl;
  cout << lis2(M) << endl;
}
