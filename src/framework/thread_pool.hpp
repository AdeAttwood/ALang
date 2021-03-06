// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <condition_variable>
#include <functional>
#include <queue>
#include <thread>

namespace framework {
// Basic thread pool implementation to run callbacks distributed across
// specified number of threads
//
// Example:
//
//  framework::ThreadPool thread_pool;
//  for (int i = 0; i < 10; i++) {
//	  thread_pool.push([i]() {
//	    std::cout << "The number is " << i << std::endl;
//	  });
//  }
//
//  thread_pool.shutdown();
//
class ThreadPool {
  std::queue<std::function<void()>> m_queue;
  bool m_stop = false;
  std::mutex m_queue_lock;
  std::vector<std::thread> m_threads;
  std::condition_variable m_condition;

  void run_job();
  void create_threads(unsigned int thread_count);

 public:
  // Create a new thread pool with the maximum number of threads you can have on
  // the current machine
  ThreadPool() { create_threads(std::thread::hardware_concurrency()); }
  // Create a thread pool that will use the specified number of threads
  explicit ThreadPool(unsigned int thread_count) { create_threads(thread_count); }
  // Push a call back function into the queue that will be run on the thread
  // pool as some time.
  void push(std::function<void()>);
  // Shuts down the thread pool and waits for the queue to be empty. This must
  // be called when all of the jobs have been pushed into the queue. This is a
  // blocking operation and will not exit until the queue is empty and all of
  // the pushed jobs have been handled.
  void shutdown();
};
}  // namespace framework
