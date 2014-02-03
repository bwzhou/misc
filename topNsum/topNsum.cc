#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::sort;
using std::make_heap;
using std::push_heap;
using std::pop_heap;

class Compare {
public:
  Compare(vector<int> *_a, vector<int> *_b, vector<int> *_f) : a(_a), b(_b), f(_f) {
  }
  bool operator() (int i, int j) {
    return (*a)[i] + (*b)[(*f)[i]] < (*a)[j] + (*b)[(*f)[j]];
  }
private:
  vector<int> *a;
  vector<int> *b;
  vector<int> *f;
};

bool numComp(int i, int j) {
  return i > j;
}

// top N sums of two lists a and b is equivalent to top N elements in the merged
// list of b.size() sorted lists
void topNsum(vector<int> &a, vector<int> &b, int N) {
  vector<int> next(a.size(), 0);
  vector<int> heap(a.size(), 0);
  Compare heapComp(&a, &b, &next);
  vector<int> result;
  make_heap(heap.begin(), heap.end(), heapComp);
  for (int i = 0; i < N; ++i) {
    int max = heap.front();
    result.push_back(a[max] + b[next[max]++]);
    pop_heap(heap.begin(), heap.end(), heapComp);
    heap.pop_back();
    heap.push_back(next[max]);
    push_heap(heap.begin(), heap.end(), heapComp);
  }
  copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  vector<int> result2;
  for (int &each_a : a)
    for (int &each_b : b)
      result2.push_back(each_a + each_b);
  sort(result2.begin(), result2.end(), numComp);
  copy(result2.begin(), result2.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main() {
  vector<int> a = {10, 8, 6, 4, 2};
  vector<int> b = {5, 4, 3, 2, 1};
  int N = 5;
  topNsum(a, b, N);
  return 0;
}
