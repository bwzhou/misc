#include <random>
#include <iostream>
#include <vector>
#include <iterator>
#include <utility>
#include <chrono>

using namespace std;

pair<int, int> partitionWithDups(vector<int> &A, int pivot, int begin, int end) {
  int s = begin, f = end;
  int i;
  for (i = s; i <= f;) {
    if (A[i] < pivot)
      swap(A[i++], A[s++]);
    else if (A[i] > pivot)
      swap(A[i], A[f--]);
    else if (A[i] == pivot)
      ++i;
  }
  // invariant:
  //  s the first element equal to pivot
  //  i one element pass the last element equal to pivot
  return make_pair(s, i);
}

void qsort(vector<int> &A, int begin, int end) {
  if (begin >= end)
    return;
  int mid = (begin + end) / 2;
  auto res = partitionWithDups(A, A[mid], begin, end);
  qsort(A, begin, res.first - 1);
  qsort(A, res.second, end);
}

int main(int argc, char **argv) {
  default_random_engine gen;
  gen.seed(time(0));
  uniform_int_distribution<int> dis(0, atoi(argv[1]));
  vector<int> A;
  for (int i = 0; i < atoi(argv[2]); ++i)
    A.emplace_back(dis(gen));
  // copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
  // cout << endl;
  auto start = chrono::steady_clock::now();
  qsort(A, 0, A.size() - 1);
  auto end = chrono::steady_clock::now();
  auto diff = end - start;
  cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
  cout << chrono::duration<double, nano>(diff).count() << " ns" << endl;
  // for (int i = 0; i < A.size() - 1; ++i) {
  //   if (A[i] > A[i + 1]) {
  //     cout << "sort failed" << endl;
  //     break;
  //   }
  // }
  // copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
  // cout << endl;
}
