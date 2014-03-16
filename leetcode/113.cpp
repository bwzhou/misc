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
    void enumPathSum(TreeNode *root, int sum, int curr, vector<int> &path, vector<vector<int>> &result) {
        path.emplace_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (root->val + curr == sum) {
                result.emplace_back(path);
            }
        }
        if (root->left) {
            enumPathSum(root->left, sum, curr + root->val, path, result);
        }
        if (root->right) {
            enumPathSum(root->right, sum, curr + root->val, path, result);
        }
        path.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        vector<int> path;
        enumPathSum(root, sum, 0, path, result);
        return result;
    }
};