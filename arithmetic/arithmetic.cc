// A simple arithmetic grammar that supports +, -, *, / and ().
// E = E + T | E - T | T
// T = T * N | T / N | N
// N = -?[0-9]+ | (E)
//
// A recursive descent parser for the above grammer.
// Alternatively one can use shunting yard algorithm to convert a infix expression
// into a postfix expression (reversed polish notation) using a queue and a stack.
// http://en.wikipedia.org/wiki/Shunting-yard_algorithm

#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using std::string;

string input;
int index;

char next() {
  if (index < input.size())
    return input[index++];
  else
    return 0;
}

char peek() {
  if (index < input.size())
    return input[index];
  else
    return 0;
}

int T();
int N();

int E() {
  int lhs = T();
  int rhs;
  char op = peek();
  while (op == '+' || op == '-') {
    next();
    rhs = T();
    switch (op) {
      case '+':
        lhs += rhs;
        break;
      case '-':
        lhs -= rhs;
        break;
    }
    op = peek();
  }
  return lhs;
}

int T() {
  int lhs = N();
  int rhs;
  char op = peek();
  while (op == '*' || op == '/') {
    next();
    rhs = T();
    switch (op) {
      case '*':
        lhs *= rhs;
        break;
      case '/':
        lhs /= rhs;
        break;
    }
    op = peek();
  }
  return lhs;
}

int N() {
  if (peek() == '(') {
    next();
    int res = E();
    assert(next() == ')');
    return res;
  }
  
  int sign = 1;
  if (peek() == '-') {
    sign = -1;
    next();
  }
  int number = 0;
  char c;
  while ((c = peek()) != 0 && c >= '0' && c <= '9') {
    number *= 10;
    number += c - '0';
    next();
  }
  number *= sign;
  return number;
}

int main(int argc, char **argv) {
  input = string(argv[1]);
  index = 0;
  cout << input << " = " << E() << endl;
}
