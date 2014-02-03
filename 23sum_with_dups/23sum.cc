#include <random>
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <tuple>
#include <iterator>

using std::default_random_engine;
using std::uniform_int_distribution;
using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::pair;
using std::make_pair;
using std::tuple;
using std::make_tuple;
using std::get;
using std::copy;
using std::ostream_iterator;

void _2sum(const vector<int> &A, const int sum, vector<pair<int, int> > *B) {
  map<int, vector<int> > indicesOf;
  for (int i = 0; i < A.size(); ++i)
    indicesOf[A[i]].push_back(i);

  for (int i = 0; i < A.size(); ++i) {
    if (indicesOf.find(sum - A[i]) != indicesOf.end()) {
      for (int &each : indicesOf[sum - A[i]]) {
        // cout << i << " and " << each << endl;
        B->push_back(make_pair(i, each));
      }
    }
  }
}

bool verify2sum(const vector<int> &A, const int sum,
                const vector<pair<int, int> > &B) {
  for (auto &each : B) {
    int tmp = A[get<0>(each)] + A[get<1>(each)];
    cout << A[get<0>(each)] << "+" << A[get<1>(each)] << "=" << tmp << endl;
    if (tmp != sum) {
      return false;
    }
  }
  return true;
}

void _3sum(const vector<int> &A, const int sum,
          vector<tuple<int, int, int> > *B) {
  map<int, vector<int> > indicesOf;
  for (int i = 0; i < A.size(); ++i)
    indicesOf[A[i]].push_back(i);

  for (int i = 0; i < A.size(); ++i) {
    for (int j = i + 1; j < A.size(); ++j) {
      if (indicesOf.find(sum - A[i] - A[j]) != indicesOf.end()) {
        for (int &each : indicesOf[sum - A[i] - A[j]]) {
          //cout << i << " and " << j << " and " << each << endl;
          B->push_back(make_tuple(i, j, each));
        }
      }
    }
  }
}

bool verify3sum(const vector<int> &A, const int sum,
                const vector<tuple<int, int, int> > &B) {
  for (auto &each : B) {
    int tmp = A[get<0>(each)] + A[get<1>(each)] + A[get<2>(each)];
    cout << A[get<0>(each)] << "+" << A[get<1>(each)] << "+" << A[get<2>(each)] << "=" << tmp << endl;
    if (tmp != sum) {
      return false;
    }
  }
  return true;
}

int main(int argc, char **argv) {
  default_random_engine gen;
  uniform_int_distribution<int> dis(-atoi(argv[1]), atoi(argv[1]));
  vector<int> A;
  for (int i = 0; i < atoi(argv[2]); ++i) {
    A.push_back(dis(gen));
  }
  copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  vector<pair<int, int> > B;
  _2sum(A, 0, &B);
  cout << "verifying 2sum: " << std::boolalpha << verify2sum(A, 0, B) << endl;
  vector<tuple<int, int, int> > C;
  _3sum(A, 0, &C);
  cout << "verifying 3sum: " << std::boolalpha << verify3sum(A, 0, C) << endl;
}
