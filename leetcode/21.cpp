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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode head(0);
        ListNode *last = &head;
        while (l1 || l2) {
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    last->next = l1;
                    l1 = l1->next;
                } else {
                    last->next = l2;
                    l2 = l2->next;
                }
            } else if (!l2) {
                last->next = l1;
                l1 = l1->next;
            } else {
                last->next = l2;
                l2 = l2->next;
            }
            last = last->next;
        }
        return head.next;
    }
};