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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        bool leftToRight = true;
        stack<TreeNode *> currLevel, nextLevel;
        currLevel.push(root);
        result.push_back(vector<int>());
        while (!currLevel.empty()) {
            TreeNode *head = currLevel.top();
            result.back().push_back(head->val);
            if (leftToRight) {
                if (head->left) nextLevel.push(head->left);
                if (head->right) nextLevel.push(head->right);
            } else {
                if (head->right) nextLevel.push(head->right);
                if (head->left) nextLevel.push(head->left);
            }
            currLevel.pop();
            if (currLevel.empty()) {
                if (!nextLevel.empty()) {
                    result.push_back(vector<int>());
                }
                swap(currLevel, nextLevel);
                leftToRight = !leftToRight;
            }
        }
        return result;        
    }
};
