#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::random_shuffle;
using std::iota;
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

void perm(vector<int> &A, vector<int> P) {
  for (int i = 0; i < A.size(); ++i) {
    if (P[i] > 0) {
      int j = i;
      while (P[j] != i) {
        int old_j = j;
        int tmp = A[j];
        A[j] = A[P[j]];
        A[P[j]] = tmp;
        j = P[j];
        P[old_j] -= P.size();
      }
      P[j] -= P.size();
    }
  }
}

int main(int argc, char **argv) {
  vector<int> A;
  for (int i = 1; i < argc; ++i) {
    A.push_back(atoi(argv[i]));
  }
  vector<int> P(A.size());
  iota(P.begin(), P.end(), 0);
  random_shuffle(P.begin(), P.end());
  cout << "A = ";
  copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  perm(A, P);
  cout << "P = ";
  copy(P.begin(), P.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << "A = ";
  copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}
