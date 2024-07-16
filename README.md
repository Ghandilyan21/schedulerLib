# Job Scheduler Library

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)

## Overview

The **Job Scheduler** library provides a simple interface to schedule and execute jobs with different priorities and periodicity. It supports both single execution and periodic jobs, delayed execution, and job priorities.

## Features

- **Job Prioritization**: Higher priority jobs execute first.
- **Periodic Jobs**: Supports jobs that repeat at regular intervals.
- **Delayed Execution**: Schedule jobs to execute after a delay or at a specific time.

## Using the Job Scheduler Library in Your Project

### Step 1: Set Up Your Project Directory

Create your project directory and ensure it looks like this:

<pre>
my_project/
├── main.cpp
├── include/
│   └── job_scheduler/  # Copy the include directory from job_scheduler
├── lib/
│   └──  # Copy the static library from job_scheduler/src
</pre>


### Step 2: Write Your `main.cpp`

Create a `main.cpp` file that uses the `JobScheduler` library:
For example

```cpp
#include <iostream>
#include <job_scheduler/job.hpp>
#include <job_scheduler/scheduler.hpp>
#include <job_scheduler/date_parser.hpp>

int main() {
    Scheduler scheduler;

    auto taskA = []() { std::cout << "Task A executed\n"; };
    auto taskB = []() { std::cout << "Task B executed\n"; };
    auto taskC = []() { std::cout << "Task C executed\n"; };

    Job jobA("Job A", 10, std::chrono::seconds(1), taskA);
    Job jobB("Job B", 50, DateParser("16/07/2024 15:25"), taskB);
    Job jobC("Job C", 5, std::chrono::seconds(0), taskC, true, std::chrono::seconds(30));

    scheduler.addJob(jobA);
    scheduler.addJob(jobB);
    scheduler.addJob(jobC);

    scheduler.start();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    scheduler.stop();

    return 0;
}
```
# Step 3: Compile and Link Your Project with g++
### You can use c++11 or higher standart
### To compile and link your project using g++, follow these steps:

<pre> 1. cd path/to/my_project</pre>
<pre> 2. g++ -std=c++11 main.cpp -Iinclude -Llib -lJobScheduler -o MyExecutable -lpthread </pre>
<pre> 3. ./MyExecutable </pre>


# After all your project will have this structure


<pre>
my_project/
├── main.cpp
├── include/
│   └── job_scheduler/
│       ├── job.hpp
│       ├── scheduler.hpp
│       ├── job_comparator.hpp
│       ├── date_parser.hpp
│       ├── job_interface.hpp
├── lib/
│   └── libJobScheduler.a 
</pre>
