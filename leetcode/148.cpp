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
/*
    ListNode *sortList(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode *slow, *quick, *prev;
        slow = head;
        quick = head;
        
        while (quick) {
            prev = slow;
            slow = slow->next;
            quick = quick->next;
            if (quick) {
                quick = quick->next;
            }
        }
        prev->next = NULL;
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        ListNode *result = NULL;
        ListNode *last = result;
        while (left && right) {
            if (left->val < right->val) {
                if (last) {
                    last->next = left;
                    last = last->next;
                } else {
                    last = left;
                    result = last;
                }
                left = left->next;
            } else {
                if (last) {
                    last->next = right;
                    last = last->next;
                } else {
                    last = right;
                    result = last;
                }
                right = right->next;
            }
        }
        if (left) {
            last->next = left;
        }
        if (right) {
            last->next = right;
        }
        return result;
    }
*/
    // return the first element after the cut.
    ListNode *cutList(ListNode *head, int len) {
        for (int i = 1; i < len && head; ++i) {
            head = head->next;
        }
        if (!head) return NULL;
        ListNode *next = head->next;
        head->next = NULL;
        return next;
    }
    
    // return the last element in the merged list.
    ListNode *mergeList(ListNode *l1, ListNode *l2, ListNode *last) {
        while (l1 || l2) {
            if (!l1) {
                last->next = l2;
                l2 = l2->next;
            } else if (!l2) {
                last->next = l1;
                l1 = l1->next;
            } else if (l1->val < l2->val) {
                last->next = l1;
                l1 = l1->next;
            } else {
                last->next = l2;
                l2 = l2->next;
            }
            last = last->next;
        }
        return last;
    }
    
    int listLen(ListNode *head) {
        int i = 0;
        while (head) {
            i++;
            head = head->next;
        }
        return i;
    }

    ListNode *sortList(ListNode *head) {
        int length = listLen(head);
        ListNode dummy = ListNode(0);
        dummy.next = head;
        for (int i = 1; i < length; i *= 2) {
            ListNode *last = &dummy;
            ListNode *start = dummy.next;
            while (start) {
                ListNode *l1 = start;
                ListNode *l2 = cutList(l1, i);
                start = cutList(l2, i);
                last = mergeList(l1, l2, last);
                last->next = start;
            } 
        }
        return dummy.next;
    }
};