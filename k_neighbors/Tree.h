#include <cassert>
#include <stack>
#include <vector>
#include <string>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int v) : val(v), left(NULL), right(NULL) {}
  TreeNode(std::string v) : val(std::stoi(v)), left(NULL), right(NULL) {}
};

struct Tree {
  TreeNode *root;
  Tree(std::vector<std::string> &tree) {
    root = deserialize(tree);
  }
  TreeNode *deserialize(std::vector<std::string> &tree) {
    std::stack<TreeNode **> last;
    last.push(&root);
    for (std::string &node : tree) {
      assert(last.size());
      TreeNode **curr = last.top();
      last.pop();
      if (node != "#") {
        *curr = new TreeNode(node);
        last.push(&(*curr)->right);
        last.push(&(*curr)->left);
      }
    }
    return root;
  }
  void serialize(std::vector<std::string> &tree) {
    serialize(tree, root);
  }
  void serialize(std::vector<std::string> &tree, TreeNode *root) {
    if (root) {
      tree.push_back(std::to_string(root->val));
      serialize(tree, root->left);
      serialize(tree, root->right);
    } else {
      tree.push_back("#");
    }
  }
};

