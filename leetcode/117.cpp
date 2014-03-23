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
        TreeLinkNode *curr = root;
        TreeLinkNode *next, *p;
        while (curr) {
            next = NULL;
            p = NULL;
            while (curr) {
                if (curr->left) {
                    if (next == NULL) next = curr->left;
                    if (p) p->next = curr->left;
                    p = curr->left;
                }
                if (curr->right) {
                    if (next == NULL) next = curr->right;
                    if (p) p->next = curr->right;
                    p = curr->right;
                }
                curr = curr->next;
            }
            curr = next;
        }
    }
};
