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
    void sumPreOrder(TreeNode *root, int runningTotal, int &sum) {
        if (root == NULL) {
            return;
        }
        runningTotal = runningTotal * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += runningTotal;
            return;
        }
        sumPreOrder(root->left, runningTotal, sum);
        sumPreOrder(root->right, runningTotal, sum);
    }
    int sumNumbers(TreeNode *root) {
        int runningTotal = 0;
        int sum = 0;
        sumPreOrder(root, runningTotal, sum);
        return sum;
    }
};