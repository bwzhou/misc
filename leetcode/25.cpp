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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(0);
        ListNode *last = &dummy;
        ListNode *begin = head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *end = head;
        while (end) {
            int i = 0;
            while (i < k - 1 && end) {
                end = end->next;
                ++i;
            }
            if (!end) {
                last->next = begin;
                break;
            }
            while (prev != end) {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            last->next = end;
            last = begin;
            begin = end = curr;
            prev = NULL;
        }
        return dummy.next;
    }
};