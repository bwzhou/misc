/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *left = root;
        while (left) {
            TreeLinkNode *curr = left;
            while (curr) {
                if (curr->left) {
                    curr->left->next = curr->right;
                }
                if (curr->right && curr->next) {
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            left = left->left;
        }
    }
};
