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
    ListNode *partition(ListNode *head, int x) {
        ListNode *left = NULL;
        ListNode *right = NULL;
        ListNode *first = NULL;
        ListNode *second = NULL;
        while (head) {
            if (head->val < x) {
                if (!first) {
                    first = head;
                }
                if (left) {
                    left->next = head;
                }
                left = head;
            } else {
                if (!second) {
                    second = head;
                }
                if (right) {
                    right->next = head;
                }
                right = head;
            }
            head = head->next;
        }
        if (right) {
            right->next = NULL;
        }
        if (left) {
            left->next = second;
            return first;
        } else {
            return second;
        }
    }
};