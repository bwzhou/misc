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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode *tail = head;
        ListNode *p = head;
        while (p) {
            ListNode *prev = NULL;
            for (ListNode *q = head; q != p; q = q->next) {
                if (q->val >= p->val) {
                    tail->next = p->next;
                    p->next = q;
                    if (prev) {
                        prev->next = p;
                    } else {
                        head = p;
                    }
                    break;
                }
                prev = q;
            }
            if (prev == tail) {
                tail = tail->next;
            }
            p = tail->next;
        }
        return head;
    }
};