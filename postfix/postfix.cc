#include <iostream>
struct Op {
  char op; // operator
  int prec;// precedence
  Op(char o, int p) : op(o), prec(p) {}
};
struct Add : public Op {
  Add() : Op('+', 1) {}
};
struct Sub : public Op {
  Sub() : Op('-', 1) {}
};
struct Mul : public Op {
  Mul() : Op('*', 2) {}
};
struct Div : public Op {
  Div() : Op('/', 2) {}
};
struct LParen : public Op {
  LParen() : Op('(', 0) {}
};
struct RParen : public Op {
  RParen() : Op(')', 0) {}
};
// convert infix expression into postfix
string convert(string in) {
  stack<Op> ops;
  string post;
  for (char each : in) {
    switch (each) {
      case '+':
      case '-':
      case '*':
      case '/':
      case '(':
      case ')':
      default:
        post.p

