#include <pthread.h>
#include <iostream>
#include <vector>
#include "defs.h"
#include "q.h"

pthread_mutex_t mutex;

/*
 * figure out what to do with conn_state
 */
enum conn_state {
  conn_todo,
  conn_ready,
  conn_wait
};

struct conn {
  int sockfd;
  enum conn_state state;
};

Queue<conn> conn_q;

int dispatch_new_conn(int sockfd) {
  conn *c = new conn();
  c->sockfd = sockfd;
  /*
   * c->state = conn_todo;
   */

  conn_q.put(c);
}

void *worker(void *arg) {
  // do some work

  pthread_mutex_lock(&mutex);
  int *data = static_cast<int*>(arg);
  std::cout << __func__ << " before:" << *data << std::endl;
  *data = pthread_self();
  std::cout << __func__ << " after:" << *data << std::endl;
  pthread_mutex_unlock(&mutex);
  pthread_exit(data);
}

int server(int port) {
  // modern way of doing things with getaddrinfo()
  
  struct addrinfo hints = {
    .ai_flags = AI_PASSIVE,     // use IPv4 or IPv6, whichever
    .ai_socktype = SOCK_STREAM, // use TCP
    .ai_family = AF_UNSPEC      // fill in my IP for me
  };
  struct addrinfo *res;
  int sockfd;
  char port_buf[PORTSTRLEN];
  struct sockaddr peer_addr;
  socklen_t addr_size;
  char s[INET6_ADDRSTRLEN];
  
  // first, load up address structs with getaddrinfo():
  
  snprintf(port_buf, sizeof(port_buf), "%d", port);
  getaddrinfo(NULL, port_buf, &hints, &res);
  
  // make a socket:
  // (you should actually walk the "res" linked list and error-check!)
  
  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  
  // bind it to the port we passed in to getaddrinfo():
  
  bind(sockfd, res->ai_addr, res->ai_addrlen);

  freeaddrinfo(res);

  listen(sockfd, LISTEN_BACKLOG);

  while (1) {
    addr_size = sizeof(peer_addr);
    new_fd = accept(sockfd, &peer_addr, &peer_addr, &addr_size);
    inet_ntop(peer_addr.ss_family, get_in_addr(&peer_addr), s, sizeof(s));
    std::cout << "server: got connection from " << s << std::endl;
    dispatch_new_conn(new_fd);
  }
}

int main (int argc, char ** argv) {
  pthread_mutex_init(&mutex, NULL);
  std::vector<pthread_t> tid(8);
  std::vector<int> data(8, 0);
  int err;

  // start the workers

  for (int i = 0; i < 8; ++i) {
    err = pthread_create(&tid[i], NULL, worker, &data[i]);
  }
  for (auto &t : tid) {
    void *o;
    pthread_join(t, &o);
    pthread_mutex_lock(&mutex);
    std::cout << __func__ << ":" << *static_cast<int*>(o) << std::endl;
    pthread_mutex_unlock(&mutex);
  }
  pthread_mutex_destroy(&mutex);

  // start the server
  server();
}
