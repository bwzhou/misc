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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        dummy.next = NULL;
        ListNode *last = &dummy;
        int carry = 0;
        while (l1 || l2 || carry > 0) {
            last->next = new ListNode(0);
            last = last->next;
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            last->val = sum % 10;
            carry = sum / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy.next;
    }
};