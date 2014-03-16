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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode dummy(0);
        dummy.next = NULL;
        ListNode *last = &dummy;
        while (!lists.empty()) {
            int minimum = INT_MAX;
            int mInd = -1;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] && lists[i]->val < minimum) {
                    minimum = lists[i]->val;
                    mInd = i;
                }
            }
            if (mInd == -1) {
                break;
            }
            last->next = lists[mInd];
            lists[mInd] = lists[mInd]->next;
            last = last->next;
            last->next = NULL;
        }
        return dummy.next;
    }
};