#include <iostream>
#include <random>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

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
        //cout << "p " << p->val << endl;
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

ListNode *sortList(ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return head;
    }
    //cout << "head " << head->val << endl;
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
    //cout << "prev " << prev->val << endl;
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

void zipList(ListNode *head) {
    ListNode *slow, *fast, *prev;
    slow = head;
    fast = head;
    prev = NULL;
    while (fast) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast) fast = fast->next;
    }
    prev->next = NULL;
    prev = NULL;
    while (slow) {
        ListNode *next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }
    ListNode *p = head;
    ListNode *q = prev;
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (p || q) {
      if (p) {
        tail->next = p;
        p = p->next;
        tail = tail->next;
      }
      if (q) {
        tail->next = q;
        q = q->next;
        tail = tail->next;
      }
    }
}

ListNode *cutList(ListNode *head, int len) {
    for (int i = 1; i < len && head; ++i) {
        head = head->next;
    }
    if (!head) return NULL;
    ListNode *next = head->next;
    head->next = NULL;
    return next;
}

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

ListNode *sortList2(ListNode *head) {
    int length = listLen(head);
    ListNode *start = head;
    ListNode dummy = ListNode(0);
    dummy.next = head;
    ListNode *last = &dummy;
    for (int i = 1; i < length; i *= 2) {
        start = dummy.next;
        last = &dummy;
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

ListNode *constructList(int maxNum, int size) {
  default_random_engine gen;
  uniform_int_distribution<int> dis(0, maxNum);
  ListNode *head = NULL;
  ListNode *tail = NULL;
  for (int i = 0; i < size; ++i) {
    ListNode *node = new ListNode(dis(gen));
    cout << node->val << " ";
    if (head == NULL) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = tail->next;
    }
  }
  cout << endl;
  return head;
}

int main(int argc, char **argv) {
  int maxNum = atoi(argv[1]);
  int size = atoi(argv[2]);

  ListNode *head = constructList(maxNum, size);
  head = sortList(head);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;

  head = constructList(maxNum, size);
  head = insertionSortList(head);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;

  head = constructList(maxNum, size);
  zipList(head);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;

  head = constructList(maxNum, size);
  head = sortList2(head);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}
