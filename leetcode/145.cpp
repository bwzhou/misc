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
    void postorderHelper(TreeNode *root, vector<int> &result) {
        if (root == NULL) return;
        postorderHelper(root->left, result);
        postorderHelper(root->right, result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }
};