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
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL) return;
        ListNode *slow, *fast, *prev;
        slow = head;
        fast = head;
        prev = NULL;
        while (fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        prev->next = NULL;
        prev = NULL;
        while (slow) {
            ListNode *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        ListNode *p = head;
        ListNode *q = prev;
        ListNode *tail = NULL;
        while (p && q) {
            if (tail) {
                tail->next = p;
            }
            tail = p;
            p = p->next;
            tail->next = q;
            tail = q;
            q = q->next;
        }
        if (p) {
            tail->next = p;
        } 
        if (q) {
            tail->next = q;
        }
    }
};