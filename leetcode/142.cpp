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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        int size = 0;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                ++size;
            }
            if (fast == slow) {
                break;
            }
        }
        if (fast == NULL) return NULL;
        slow = fast = head;
        for (int i = 0; i < size; ++i) {
            fast = fast->next;
        }
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
