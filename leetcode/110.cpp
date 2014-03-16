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
    pair<bool, int> check(TreeNode *root) {
        if (root == NULL) {
            return make_pair(true, 0);
        }
        pair<bool, int> left = check(root->left);
        pair<bool, int> right = check(root->right);
        int diff = abs(left.second - right.second);
        return make_pair(left.first && right.first && diff <= 1, max(left.second, right.second) + 1);
    }
    bool isBalanced(TreeNode *root) {
        return check(root).first;
    }
};