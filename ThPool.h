#pragma once
#include <iostream>
#include <queue>
#include <future>
#include <condition_variable>
#include <vector>
#include <chrono>
#include <thread>

void taskFunc(int id, int delay);
typedef std::function<void()> task_type;
typedef void (*FuncType) (int, int);

class ThreadPool {
public:
    void start();
    void stop();
    void push_task(FuncType f, int id, int arg);
    void threadFunc();
private:
    std::vector<std::thread> m_threads;
    std::mutex m_locker;
    std::queue<task_type> m_task_queue;
    std::condition_variable m_event_holder;
    volatile bool m_work;
};