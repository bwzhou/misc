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
    void find(TreeNode *root, TreeNode *&prev, TreeNode *&left, TreeNode *&right) {
        if (root->left) {
            find(root->left, prev, left, right);
        }
        if (prev && prev->val > root->val) {
            if (left == NULL) {
                left = prev;
            }
            right = root;
        }
        prev = root;
        if (root->right) {
            find(root->right, prev, left, right);
        }
    }
    void recoverTree(TreeNode *root) {
        if (root) {
            TreeNode *left = NULL, *right = NULL, *prev = NULL;
            find(root, prev, left, right);
            if (left && right) {
                swap(left->val, right->val);
            }
        }
    }
};