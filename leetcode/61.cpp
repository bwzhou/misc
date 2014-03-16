/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) {
            return NULL;
        }
        if (k == 0) {
            return head;
        }
        ListNode *fast, *slow;
        ListNode *prevSlow = NULL;
        ListNode *prevFast = NULL;
        int size = 0;
        fast = head;
        while (fast) {
            ++size;
            fast = fast->next;
        }
        if (k % size == 0) {
            return head;
        }
        fast = slow = head;
        for (int i = 0; i < k % size; ++i) {
            prevFast = fast;
            fast = fast->next;
        }
        while (fast) {
            prevSlow = slow;
            slow = slow->next;
            prevFast = fast;
            fast = fast->next;
        }
        prevFast->next = head;
        prevSlow->next = NULL;
        return slow;
    }
};