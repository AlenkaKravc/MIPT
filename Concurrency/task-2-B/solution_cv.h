#pragma once

#include <iostream>
#include <mutex>
#include <atomic>
#include <condition_variable>

class Robot {
public:
    Robot():previos_right_(true){}; // считаем что в самом начале был сделан правый шаг
    void StepLeft() {
        std::unique_lock<std::mutex> lock(mtx_);
        if (!previos_right_) {
            cv_.wait(lock);
        }
        previos_right_=false;
        std::cout << "left" << std::endl;
        cv_.notify_one();
    }
    void StepRight(){
        std::unique_lock<std::mutex> lock(mtx_);
        if (previos_right_) {
            cv_.wait(lock);
        }
        previos_right_ = true;
        std::cout << "right" << std::endl;
        cv_.notify_one();
    }
private:
    std::mutex mtx_;
    std::atomic<bool> previos_right_; // флажок того, что был сделан правый шаг
    std::condition_variable cv_;
};


