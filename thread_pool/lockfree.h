// A lock-free queue shared by multiple producers and consumers though at any
// given instance only a single producer and a single consumer are allowed to
// update the queue.
#include <atomic>

using namespace std;

template <typename T>
class LockFreeQueue {
public:
  LockFreeQueue() {
    last = first = new Node(nullptr);
    consumerLock = producerLock = false;
  }
  ~LockFreeQueue() {
    while (first != nullptr) {
      Node *tmp = first;
      first = first->next;
      delete tmp->value;
      delete tmp;
    }
  }
  // Producer
  void push(const T &t) {
    Node *tmp = new Node(new T(t)); // do the work
    while (producerLock.exchange(true))
      ; // acquire exclusivity
    last->next = tmp; // publish to consumers
    last = tmp;
    producerLock = false;
  }
  // Consumer
  bool try_pop(T &result) {
    while (consumerLock.exchange(true))
      ;
    Node *theFirst = first;
    Node *theNext = first->next;
    // check to see if the next pointer has been published by producer
    // * not check if first equals to last so no need to set last atomic
    // * further updates from producers won't flip the condition
    if (theNext != nullptr) {
      T *val = theNext->value;
      theNext->value = nullptr; // make sure the first dummy node contains no T
      first = theNext;
      consumerLock = false;
      result = *val;
      delete val;
      delete theFirst;
      return true;
    } else {
      consumerLock = false;
      return false;
    }
  }
  bool empty() const {
    return first->next == nullptr;
  }
private:
  struct Node {
    Node(T *val) : value(val), next(nullptr) { }
    T *value;
    atomic<Node *> next; // shared by producers and consumers
  };
  atomic<bool> consumerLock, producerLock;
  Node *first, *last;
};
