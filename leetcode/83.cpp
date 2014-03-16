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
        if (head == NULL) {
            return NULL;
        }
        ListNode *i = head;
        ListNode *j = head->next;
        while (j) {
            if (i->val != j->val) {
                i->next = j;
                i = i->next;
            }
            j = j->next;
        }
        i->next = NULL;
        return head;
    }
};