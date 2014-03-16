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
    bool compare(TreeNode *left, TreeNode *right) {
        if (left == NULL && right != NULL ||
            left != NULL && right == NULL ||
            left != NULL && right != NULL && left->val != right->val) {
            return false;
        }
        if (left == NULL && right == NULL) {
            return true;
        }
        return compare(left->left, right->right) && compare(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        return compare(root->left, root->right);
    }
};