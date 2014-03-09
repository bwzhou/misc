template<typename T>
class Queue {
private:
  struct Item {
    T *data;
    Item *next;
    pthread_mutex_t lock; // make next atomic

    Item(T *d) : data(d), next(NULL) {
      pthread_mutex_init(&lock, NULL);
    }
  };
  Item *first;
  Item *last;
  pthread_mutex_t producerLock;
  pthread_mutex_t consumerLock;
public:
  Queue() {
    pthread_mutex_init(&producerLock);
    pthread_mutex_init(&consumerLock);
    first = last = new Item(0);
  }
  ~Queue() {
    Item *n = NULL;
    while (first) {
      n = first->next;
      if (first->data) { 
        delete first->data;
      }
      delete first;
      first = n;
    }
  }
  void put(T *data) {
    Item *n = new Item(data);
    pthread_mutex_lock(&producerLock);

    // emulate atomic write

    pthread_mutex_lock(&last->lock);
    last->next = n;
    pthread_mutex_unlock(&last->lock);

    last = last->next;
    pthread_mutex_unlock(&producerLock);
  }
  void get(T *data) {
    pthread_mutex_lock(&consumerLock);

    // emulate atomic read

    while (true) {
      pthread_mutex_lock(&first->lock);
      if (first->next) {
        pthread_mutex_unlock(&first->lock);
        break;
      }
      pthread_mutex_unlock(&first->lock);
    }

    Item *n = first->next;
    Item *f = first;
    first = first->next; // n becomes the new first
    pthread_mutex_unlock(&consumerLock);
    *data = *n->data;
    delete n->data;
    n->data = NULL;
    delete f;
  }
};
