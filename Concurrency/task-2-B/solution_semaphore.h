#pragma once

#include <iostream>
#include <mutex>
#include <condition_variable>

class Semaphore {
public:
    Semaphore():counter_(0){};
    Semaphore(std::size_t count): counter_(count){};
    void wait(){
        std::unique_lock<std::mutex> lock(mtx_);
       if ( counter_ == 0 ) {
            cv_.wait(lock);
        }
        counter_--;
    }
    void signal(){
        std::unique_lock<std::mutex> lock(mtx_);
        counter_++;
        if ( counter_ > 0 ){
            cv_.notify_one();
        }
    }
private:
    std::size_t counter_;
    std::mutex mtx_;
    std::condition_variable cv_;
};

class Robot {
public:
    Robot(){
        left_step_.signal(); //первый левый шаг
    };
    void StepLeft() {
        left_step_.wait();
        std::cout << "left" << std::endl;
        right_step_.signal();
    }
    void StepRight(){
        right_step_.wait();
        std::cout << "right" << std::endl;
        left_step_.signal();
    }
private:
    std::mutex mtx_;
    Semaphore left_step_, right_step_;
};


