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
    TreeNode *build(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd) {
        if (inStart >= inEnd || postStart >= postEnd) {
            return NULL;
        }
        int val = postorder[postEnd - 1];
        TreeNode *curr = new TreeNode(val);
        int mid;
        for (mid = inStart; mid < inEnd; ++mid) {
            if (inorder[mid] == val) {
                break;
            }
        }
        curr->left = build(inorder, inStart, mid, postorder, postStart, postStart + mid - inStart);
        curr->right = build(inorder, mid + 1, inEnd, postorder, postStart + mid - inStart, postEnd - 1);
        return curr;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};