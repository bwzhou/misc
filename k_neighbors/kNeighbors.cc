#include "Tree.h"
#include <vector>
#include <iostream>

using namespace std;

// find all nodes that are k hops aways from target
void kNeighbor(TreeNode *root, TreeNode *target, int k) {
}

int main() {
  vector<string> tree{"6", "3", "1", "#", "#", "4", "#", "5", "#", "#", "7", "#", "8", "#", "9", "#", "#"};
  for (string &node : tree) {
    cout << node << " ";
  }
  cout << endl;
  Tree t(tree);
  vector<string> copy;
  t.serialize(copy);
  for (string &node : copy) {
    cout << node << " ";
  }
  cout << endl;
}
