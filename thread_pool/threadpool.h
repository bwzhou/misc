// The simplest thread pool implementation from the book "C++ Concurrency in Action"
#include <atomic>
#include <functional>
#include <vector>
#include <thread>
#include <mutex>
#include "lockfree.h"
#include "work.h"

class ThreadPool {
  std::atomic<bool> done;
  LockFreeQueue<Work::Callable> work_queue;
  std::vector<thread> threads;
  std::mutex output_mutex;
  void worker_thread() {
    int tasks = 0;
    while (!done) {
      Work::Callable task;
      if (work_queue.try_pop(task)) {
        if (task() == Work::Type::FINISH) {
          break;
        }
        ++tasks;
      } else {
        std::this_thread::yield();
      }
    }
    std::thread::id my_id = std::this_thread::get_id();
    output_mutex.lock();
    std::cout << my_id << " finished " << tasks << " tasks\n";
    output_mutex.unlock();
  }
public:
  ThreadPool() : done(false) {
    unsigned const thread_count = std::thread::hardware_concurrency();
    try {
      for (unsigned i = 0; i < thread_count; ++i) {
        threads.push_back(std::thread(&ThreadPool::worker_thread, this));
      }
    } catch (...) {
      done = true;
      throw;
    }
  }
  ~ThreadPool() {
    //done = true;
    for (int i = 0; i < threads.size(); ++i) {
      work_queue.push(Work::Callable([]() {
        return Work::Type::FINISH;
      }));
    }
    for (auto &each : threads) {
      if (each.joinable()) {
        each.join();
      }
    }
  }
  template<typename FunctionType>
  void submit(FunctionType f) {
    work_queue.push(Work::Callable([f]() {
      f();
      return Work::Type::CONTINUE;
    }));
  }
};
