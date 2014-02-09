#include <iostream>
#include <cstdlib>
using namespace std;
void count(string &s, int start, int &i) {
  if (start == s.size()) {
    ++i;
    return;
  }
  if (s[start] == '0') {
    return;
  }
  count(s, start + 1, i);
  if (s.size() - start >= 2 && atoi(s.substr(start, 2).c_str()) <= 26) {
    count(s, start + 2, i);
  }
}
int numDecodings(string s) {
  int i = 0;
  count(s, 0, i);
  return i;
}
int main() {
  cout << numDecodings("9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253") << endl;
}
