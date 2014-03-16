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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int i = 1;
        ListNode *last = NULL;
        ListNode *curr = head;
        while (i < m && curr) {
            last = curr;
            curr = curr->next;
            ++i;
        }
        ListNode *theLast = last;
        ListNode *theStart = curr;
        while (i < n && curr) {
            ListNode *next = curr->next;
            curr->next = last;
            last = curr;
            curr = next;
            ++i;
        }
        if (curr) {
            if (theStart != curr) { // m == n
                theStart->next = curr->next;
                curr->next = last;
            }
            if (theLast) { // m == 1
                theLast->next = curr;
            } else {
                head = curr;
            }
        }
        return head;
    }
};