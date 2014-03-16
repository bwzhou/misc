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
    TreeNode *transform(vector<int> &num, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = transform(num, start, mid - 1);
        root->right = transform(num, mid + 1, end);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return transform(num, 0, num.size() - 1);
    }
};