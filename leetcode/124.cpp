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
    int maxPathSum(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        map<TreeNode *, int> maxToLeaf;
        maxToLeaf[NULL] = 0;
        stack<TreeNode *> worklist;
        TreeNode *curr = root;
        TreeNode *prev = NULL;
        int maxPath = root->val;
        while (curr || !worklist.empty()) {
            if (curr) {
                worklist.push(curr);
                curr = curr->left;
            } else {
                TreeNode *peek = worklist.top();
                if (peek->right == NULL || prev == peek->right) {
                    int maxLeft = maxToLeaf[peek->left];
                    int maxRight = maxToLeaf[peek->right];
                    maxPath = max(maxPath, peek->val);
                    maxPath = max(maxPath, maxLeft + peek->val);
                    maxPath = max(maxPath, peek->val + maxRight);
                    maxPath = max(maxPath, maxLeft + peek->val + maxRight);
                    maxToLeaf[peek] = max(max(maxLeft, maxRight) + peek->val, peek->val);
                    
                    worklist.pop();
                    prev = peek;
                } else {
                    curr = peek->right;
                }
            }
        }
        return maxPath;
    }
};