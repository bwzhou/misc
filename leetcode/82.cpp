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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(0);
        dummy.next = NULL;
        ListNode *i, *j, *last;
        i = j = head;
        last = &dummy;
        while (j) {
            if (j->val != i->val) {
                if (j == i->next) {
                    last->next = i;
                    last = last->next;
                }
                i = j;
            }
            j = j->next;
        }
        // When splitting a list remember to handle the end of list as a separator
        if (i && i->next == NULL) {
            last->next = i;
            last = last->next;
        }
        // Cut the original link after the last element in the list
        last->next = NULL;
        return dummy.next;
    }
};