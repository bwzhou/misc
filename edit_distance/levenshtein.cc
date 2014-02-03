#include <algorithm>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;
int levenshtein(string a, string b) {
  int d;
  if (a.empty() || b.empty()) {
    d = abs((int) a.size() - (int) b.size());
  } else {
    d = min({levenshtein(a.substr(0, a.size() - 1), b) + 1,
             levenshtein(a, b.substr(0, b.size() - 1)) + 1,
             levenshtein(a.substr(0, a.size() - 1),
                         b.substr(0, b.size() - 1)) + (a.back() != b.back())
            });
  }
  // cout << " a=" << a << " a.size=" << a.size()
  //      << " b=" << b << " b.size=" << b.size()
  //      << " d=" << d << endl;
  return d;
}

int main(int argc, char **argv) {
  cout << levenshtein(argv[1], argv[2]) << endl;
  return 0;
}
