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
    vector<TreeNode *> generate(int start, int end) {
        vector<TreeNode *> result;
        if (start > end) {
            result.push_back(NULL);
            return result;
        }
        for (int i = start; i <= end; ++i) {
            for (auto &left : generate(start, i - 1)) {
                for (auto &right : generate(i + 1, end)) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }
};