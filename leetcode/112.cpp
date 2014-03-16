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
    bool checkPathSum(TreeNode *root, int sum, int curr) {
        if (root->left == NULL && root->right == NULL) {
            if (root->val + curr == sum) {
                return true;
            } else {
                return false;
            }
        }
        return (root->left && checkPathSum(root->left, sum, root->val + curr)) ||
               (root->right && checkPathSum(root->right, sum, root->val + curr));
    }
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return false;
        }
        int curr = 0;
        return checkPathSum(root, sum, curr);
    }
};