/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *curr = root;
        stack<TreeNode *> s;
        vector<int> result;
        while (curr || s.size()) {
            if (curr) {
                s.push(curr);
                curr = curr->left;
            } else {
                TreeNode *top = s.top();
                s.pop();
                result.push_back(top->val);
                curr = top->right;
            }
        }
        return result;
    }
};