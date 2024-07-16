#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <iostream>
#include <string>
#include <set>
#include <thread>
#include <memory>
#include <mutex>
#include "job_interface.hpp"
#include "job.hpp"
#include "job_comparator.hpp"

class Scheduler {
public:
    Scheduler();
    void addJob(const Job& job);
    void addJob(Job* job);
    void deleteJob(const std::string& name);
    void start();
    void stop();
    void singleStep();
    void print();
    ~Scheduler();
private:
    std::multiset<Job, JobComparator> jobs;
    bool running;
    std::thread schedulerThread;
    std::mutex mtx;
    void execute();
};

#endif

