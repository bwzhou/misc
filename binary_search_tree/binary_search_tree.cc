#include <iostream>
#include <cstdlib>
#include <random>
#include <iterator>
#include <vector>
#include <iterator>
#include <stack>

using std::cout;
using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::vector;
using std::ostream_iterator;
using std::stack;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node *next;
  Node(int d) : data(d), left(0), right(0), next(0) {
  }
  static void print(Node *n) {
    cout << n->data << endl;
  }
};

class Tree {
private:
  Node *root;
public:
  Tree() : root(0) {
  }
  void insert(int d) {
    insert(root, d);
  }
  void threading() {
    threading(root);
  }
  void printThreaded() {
    printThreaded(root);
  }
  void printInOrder() {
    printInOrder(root);
  }
  void serialize(vector<int> &output) {
    serialize(root, output);
  }
  void deserialize(vector<int> &input) {
    deserialize(root, input, 0, input.size() - 1);
  }
  void traversePreOrder(void (*visit)(Node *)) {
    cout << "PreOrder Traversal:" << endl;
    traversePreOrder(root, visit);
  }
  void traverseInOrder(void (*visit)(Node *)) {
    cout << "InOrder Traversal:" << endl;
    traverseInOrder(root, visit);
  }
  void traversePostOrder(void (*visit)(Node *)) {
    cout << "PostOrder Traversal:" << endl;
    traversePostOrder(root, visit);
  }
private:
  void insert(Node *&root, int d) {
    if (root == NULL) {
      root = new Node(d);
      //cout << root->data << endl;
      return;
    }
    if (d < root->data) {
      insert(root->left, d);
    } else if (d > root->data) {
      insert(root->right, d);
    }
  }
  void threading(Node *root) {
    Node *q0 = NULL;
    Node *q = NULL;
    Node *p = root;
    while (p) {
      if (p->left) {
        if (q0 == NULL) q0 = p->left;
        if (q) q->next = p->left;
        q = p->left;
      }
      if (p->right) {
        if (q0 == NULL) q0 = p->right;
        if (q) q->next = p->right;
        q = p->right;
      }
      p = p->next;
    }
    if (q0) threading(q0);
  }
  void printThreaded(Node *root) {
    Node *p = root;
    Node *q0 = NULL;
    while (p) {
      if (q0 == NULL && p->left)
        q0 = p->left;
      if (q0 == NULL && p->right)
        q0 = p->right;
      cout << p->data;
      if (p->next)
        cout << " ";
      else
        cout << endl;
      p = p->next;
    }
    if (q0) printThreaded(q0);
  }
  void printInOrder(Node *root) {
    Node *last = NULL;
    vector<Node *> stack;
    vector<int> result;
    stack.emplace_back(root);
    while (!stack.empty()) {
      Node *top = stack.back();
      if (top->left && top->left == last) {
        result.emplace_back(top->data);
        if (top->right) {
          stack.emplace_back(top->right);
        } else {
          last = top;
          stack.pop_back();
        }
      } else if (top->right && top->right == last) {
        last = top;
        stack.pop_back();
      } else if (top->left) {
        stack.emplace_back(top->left);
      } else if (top->right) {
        result.emplace_back(top->data);
        stack.emplace_back(top->right);
      } else {
        result.emplace_back(top->data);
        last = top;
        stack.pop_back();
      }
    }
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
  }
  void traverseInOrder(Node *root, void (*visit)(Node *)) {
    Node *cur = root;
    stack<Node *> s;
    while (cur || !s.empty()) {
      if (cur) {
        s.push(cur);
        cur = cur->left;
      } else {
        cur = s.top();
        (*visit)(cur);
        s.pop();
        cur = cur->right;
      }
    }
  }
  void traversePreOrder(Node *root, void (*visit)(Node *)) {
    Node *cur;
    stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
      cur = s.top();
      s.pop();
      (*visit)(cur);
      if (cur->right)
        s.push(cur->right);
      if (cur->left)
        s.push(cur->left);
    }
  }
  void traversePostOrder(Node *root, void (*visit)(Node *)) {
    Node *prev = NULL, *cur = root;
    stack<Node *> s;
    while (cur || !s.empty()) {
      if (cur) {
        s.push(cur);
        cur = cur->left;
      } else {
        Node *peek = s.top();
        if (peek->right && prev != peek->right) {
          cur = peek->right;
        } else {
          s.pop();
          visit(peek);
          prev = peek;
        }
      }
    }
  }
  void serialize(Node *root, vector<int> &result) {
    result.push_back(root->data);
    if (root->left)
      serialize(root->left, result);
    if (root->right)
      serialize(root->right, result);
  }
  void deserialize(Node *&root, vector<int> &input, int start, int end) {
    if (start > end) return;
    int i;
    root = new Node(input[start]); 
    for (i = start + 1; i <= end && input[i] < input[start]; ++i);
    deserialize(root->left, input, start + 1, i - 1);
    deserialize(root->right, input, i, end);
  }
};

int main(int argc, char **argv) {
  default_random_engine gen;
  uniform_int_distribution<int> dis(0, atoi(argv[1]));
  Tree t;
  for (int i = 0; i < atoi(argv[2]); ++i) {
    t.insert(dis(gen));
  }
  t.threading();
  t.printThreaded();
  t.printInOrder();
  vector<int> serial;
  t.serialize(serial);
  Tree t2;
  t2.deserialize(serial);
  t2.printInOrder();
  t.traversePreOrder(Node::print);
  t.traverseInOrder(Node::print);
  t.traversePostOrder(Node::print);
}
