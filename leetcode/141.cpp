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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return NULL;
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        int slowSteps = 1;
        int fastSteps = 2;
        bool hasCycle = false;
        while (fast) {
            if (fast == slow) {
                hasCycle = true;
                break;
            }
            slow = slow->next;
            ++slowSteps;
            fast = fast->next;
            ++fastSteps;
            if (fast) {
                fast = fast->next;
                ++fastSteps;
            }
        }
        return hasCycle;
    }
};