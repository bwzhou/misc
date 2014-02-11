#include <string>
#include <iostream>
using namespace std;

int main() {
  string A = "hello";
  int cur = 1;
  cout << -10 << endl;
  cout << (int) string::npos << endl;
  cout << (int) string::npos - cur << endl;
  cout << A.substr(cur, string::npos - cur) << endl;
  cout << A.substr(cur, -1000) << endl;
}
