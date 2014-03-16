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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p = head;
        ListNode *q = head;
        ListNode *prev = NULL;
        while (p && n > 0) {
            p = p->next;
            --n;
        }
        while (p) {
            p = p->next;
            prev = q;
            q = q->next;
        }
        if (prev) {
            prev->next = q->next;
        } else {
            head = head->next;
        }
        return head;
    }
};