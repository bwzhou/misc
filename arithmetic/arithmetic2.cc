#include <iostream>
#include <stack>
using namespace std;
int calculate(string expr) {
  stack<int> nums;
  stack<char> ops;
  int start = 0;
  while (start < expr.size()) {
    int num = 0;
    while (start < expr.size() && isdigit(expr[start])) {
      num *= 10;
      num += expr[start] - '0';
      ++start;
    }
    nums.push(num);
    if (start < expr.size()) {
      char op = expr[start];
      while (!ops.empty()) {
        char last = ops.top();
        if ((op == '*' || op == '/') &&
            (last == '+' || last == '-')) {
          break;
        }
        int rhs = nums.top();
        nums.pop();
        int lhs = nums.top();
        nums.pop();
        switch (last) {
          case '+':
            nums.push(lhs + rhs);
            break;
          case '-':
            nums.push(lhs - rhs);
            break;
          case '*':
            nums.push(lhs * rhs);
            break;
          case '/':
            nums.push(lhs / rhs);
            break;
        }
        ops.pop();
      }
      ops.push(op);
      ++start;
    }
  }
  while (!ops.empty()) {
    char last = ops.top();
    int rhs = nums.top();
    nums.pop();
    int lhs = nums.top();
    nums.pop();
    switch (last) {
      case '+':
        nums.push(lhs + rhs);
        break;
      case '-':
        nums.push(lhs - rhs);
        break;
      case '*':
        nums.push(lhs * rhs);
        break;
      case '/':
        nums.push(lhs / rhs);
        break;
    }
    ops.pop();
  }
  return nums.top();
}

int main() {
  cout << calculate("10+2*5-6/3") << endl;
}

