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
    void preorderHelper(TreeNode *root, vector<int> &result) {
        if (root == NULL) return;
        result.push_back(root->val);
        preorderHelper(root->left, result);
        preorderHelper(root->right, result);
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }
};