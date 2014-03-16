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
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(0);
        ListNode *last = &dummy;
        ListNode *prev = head;
        ListNode *curr, *next;
        while (prev) {
            curr = prev->next;
            if (!curr) {
                last->next = prev;
                break;
            }
            next = curr->next;
            
            last->next = curr;
            curr->next = prev;
            prev->next = NULL;
            last = prev;
            
            prev = next;
        }
        return dummy.next;
    }
};