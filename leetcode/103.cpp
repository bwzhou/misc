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
        int from = 0;
        int to = 1;
        vector<vector<TreeNode *>> S(2);
        S[from].push_back(root);
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        result.push_back(vector<int>{root->val});
        while (!S[0].empty() || !S[1].empty()) {
            TreeNode *head = S[from].back();
            if (from == 1) {
                if (head->left) {
                    S[to].push_back(head->left);
                }
                if (head->right) {
                    S[to].push_back(head->right);
                }
            } else {
                if (head->right) {
                    S[to].push_back(head->right);
                }
                if (head->left) {
                    S[to].push_back(head->left);
                }
            }
            S[from].pop_back();
            if (S[from].empty()) {
                vector<int> tmp;
                for (auto &each : S[to]) {
                    tmp.push_back(each->val);
                }
                if (!tmp.empty()) {
                    result.push_back(tmp);
                }
                swap(from, to);
            }
        }
        return result;        
    }
};