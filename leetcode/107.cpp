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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        deque<TreeNode *> worklist;
        worklist.emplace_back(root);
        int size = 1;
        result.emplace_back(vector<int>{root->val});
        while (!worklist.empty()) {
            TreeNode *head = worklist.front();
            if (head->left) {
                worklist.emplace_back(head->left);
            }
            if (head->right) {
                worklist.emplace_back(head->right);
            }
            worklist.pop_front();
            --size;
            if (size == 0 && worklist.size() > 0) {
                vector<int> tmp;
                for (auto &each : worklist) {
                    tmp.emplace_back(each->val);
                }
                result.emplace_back(tmp);
                size = worklist.size();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};