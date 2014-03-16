/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        ListNode *first = NULL;
        if (prev) {
            first = head;
            prev->next = NULL;
        }
        ListNode *second = slow->next;
        root->left = sortedListToBST(first);
        root->right = sortedListToBST(second);
        return root;
    }
};