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
    void flattenHelper(TreeNode *curr, TreeNode *&prev) {
        if (curr) {
            prev->left = NULL;
            prev->right = curr;
            prev = curr;
            TreeNode *right = curr->right;
            flattenHelper(curr->left, prev);
            flattenHelper(right, prev);
        }
    }
    void flatten(TreeNode *root) {
        TreeNode *prev = root;
        if (root) {
            TreeNode *right = root->right;
            flattenHelper(root->left, prev);
            flattenHelper(right, prev);
        }
    }
};