#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;
using std::ostream_iterator;

int binarySearch(const vector<int> &A, const int V) {
    int s = 0, f = A.size() - 1;
    while (s <= f) {
        int m = (s + f) / 2;
        cout << m << ":" << A[m] << endl;
        if (A[m] < V) {
            s = m + 1;
        } else if (A[m] > V) {
            f = m - 1;
        } else {
            return m;
        }
    }
    return s;
}

int main(int argc, char** argv) {
  default_random_engine gen((random_device())());
  uniform_int_distribution<int> dis(1, atoi(argv[1]));
  vector<int> A;
  for (int i = 0; i < atoi(argv[2]); ++i) {
    A.emplace_back(dis(gen));
  }
  sort(A.begin(), A.end());
  cout << "A = ";
  copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  uniform_int_distribution<int> i_dis(0, A.size() - 1);
  int V = i_dis(gen);
  cout << "V = " << A[V] << endl;
  cout << "Result: A[" << binarySearch(A, A[V]) << "]" << endl;

  V = dis(gen);
  cout << "V = " << V << endl;
  cout << "Resule: A[" << binarySearch(A, V) << "]" << endl;
}
