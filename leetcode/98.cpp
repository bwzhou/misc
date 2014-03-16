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
    bool checkBST(TreeNode *root, int low, int high) {
        if (root == NULL) {
            return true;
        }
        if (root->val <= low || root->val >= high) {
            return false;
        }
        return checkBST(root->left, low, root->val) && checkBST(root->right, root->val, high);
    }
    bool isValidBST(TreeNode *root) {
        return checkBST(root, -INT_MAX, INT_MAX);
    }
};