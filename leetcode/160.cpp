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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int i = 0;
        ListNode *cur = headA;
        while (cur) {
            ++i;
            cur = cur->next;
        }
        int j = 0;
        cur = headB;
        while (cur) {
            ++j;
            cur = cur->next;
        }
        ListNode *longer, *shorter;
        longer = i > j ? headA : headB;
        shorter = i > j ? headB : headA;
        for (int k = 0; k < abs(i - j); ++k) {
            longer = longer->next;
        }
        while (longer && shorter) {
            if (longer == shorter) {
                return longer;
            }
            longer = longer->next;
            shorter = shorter->next;
        }
        return NULL;
    }
};
