#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
string convert(string s, int nRows) {
    string res;
    if (nRows == 1) {
      return s;
    }
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < (int) s.size() - i; j += (nRows - 1) * 2) {
            res += s[i + j];
            if (i != 0 && i != nRows - 1 && i + j + (nRows - 1 - i) * 2 < s.size()) {
                res += s[i + j + (nRows - 1 - i) * 2];
            }
        }
    }
    return res;
}

int main(int argc, char **argv) {
    cout << convert(argv[1], atoi(argv[2])) << endl;
}
