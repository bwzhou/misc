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
    TreeNode *build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd) {
        if (preStart >= preEnd || inStart >= inEnd) {
            return NULL;
        }
        int val = preorder[preStart];
        TreeNode *curr = new TreeNode(val);
        int mid;
        for (mid = inStart; mid < inEnd; ++mid) {
            if (inorder[mid] == val) {
                break;
            }
        }
        curr->left = build(preorder, preStart + 1, preStart + 1 + mid - inStart, inorder, inStart, mid);
        curr->right = build(preorder, preStart + 1 + mid - inStart, preEnd, inorder, mid + 1, inEnd);
        return curr;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};