/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *dup = NULL;
        RandomListNode *curr = head;
        RandomListNode *next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = new RandomListNode(curr->label);
            curr->next->next = next;
            curr = next;
        }
        curr = head;
        while (curr) {
            if (curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        curr = head;
        if (head) dup = head->next;
        while (curr) {
            next = curr->next;
            if (next) curr->next = next->next;
            curr = next;
        }
        return dup;
    }
};