//Input:
//  3
//  (a+(b*c))
//  ((a+b)*(z+x))
//  ((a+t)*((b+(a+c))^(c+d)))
//Output:
//  abc*+
//  ab+zx+*
//  at+bac++cd+^*

#include <vector>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
void onp(string &e) {
  stack<char> op;
  string res;
  for (int i = 0; i < e.size(); ++i) {
    char each = e[i];
    if (each == '+') {
      while (!op.empty() && op.top() != '(') {
        res += op.top();
        op.pop();
      }
      op.push(each);
    } else if (each == '-') {
      while (!op.empty() && op.top() != '(' && op.top() != '+') {
        res += op.top();
        op.pop();
      }
      op.push(each);
    } else if (each == '*') {
      while (!op.empty() && op.top() != '(' && op.top() != '+' && op.top() != '-') {
        res += op.top();
        op.pop();
      }
      op.push(each);
    } else if (each == '/') {
      while (!op.empty() && op.top() != '(' && op.top() != '+' && op.top() != '-' && op.top() != '*') {
        res += op.top();
        op.pop();
      }
      op.push(each);
    } else if (each == '^') {
      while (!op.empty() && op.top() != '(' && op.top() != '+' && op.top() != '-' && op.top() != '*' && op.top() != '/') {
        res += op.top();
        op.pop();
      }
      op.push(each);
    } else if (each == '(') {
      op.push(each);
    } else if (each == ')') {
      while (!op.empty() && op.top() != '(') {
        res += op.top();
        op.pop();
      }
      if (op.top() == '(') {
        op.pop();
      }
    } else {
      res += each;
    }
  }
  cout << res << endl;
}
int main() {
  int l;
  cin >> l;
  string e;
  for (int i = 0; i < l; ++i) {
    cin >> e;
    onp(e);
  }
}
