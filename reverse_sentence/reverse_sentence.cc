#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::swap;
using std::string;

void reverse(string &A) {
    int s = 0, f = A.size() - 1;
    while (s < f) {
        swap(A[s++], A[f--]);
    }
    s = f = 0;
    while (s < A.size() && f < A.size()) {
        while (s < A.size() && A[s] == ' ') s++;
        f = s;
        while (f < A.size() && A[f] != ' ') f++;
        int i = s, j = f - 1;
        while (i < j) {
            swap(A[i++], A[j--]);
        }
        s = f;
    }
}

int main(int argc, char **argv) {
  string A(argv[1]);
  cout << A << endl;
  reverse(A);
  cout << A << endl;
}

