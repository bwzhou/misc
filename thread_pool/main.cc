#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>
#include "threadpool.h"

using namespace std;

int doSomething() {
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main() {
  ThreadPool pool;
  for (int i = 0; i < 100; ++i) {
    pool.submit(&doSomething);
  }
}
