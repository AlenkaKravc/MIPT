#pragma once

#include <thread>
#include <atomic>
#include <condition_variable>
#include <mutex>



template <class ConditionVariable = std::condition_variable>
class CyclicBarrier{
public:
    CyclicBarrier(size_t num_threads) : num_threads(num_threads), inside(0), barrierState(false){};
    // Конструктор по-умолчанию, конструктор копирования и оператор присваивания запрещены
    CyclicBarrier() = delete;
    CyclicBarrier(const CyclicBarrier &otherBarrier) = delete;
    CyclicBarrier &operator=(const CyclicBarrier &otherCyclicBarrier) = delete;
    // Деструктор - по-умолчанию
    ~CyclicBarrier() = default;
    void Pass();
private:
    std::size_t num_threads; // Число потоков, которые будут проходить через барьер, задаётся при создании в конструкторе
    std::atomic<std::size_t> inside; //число потоков, находящихся внутри барьера
    std::mutex mtx; // Мьютекс на проход через барьер
    ConditionVariable cv;
    bool barrierState; //Состояние барьера, true - когда через него начали проодить потоки
};



void CyclicBarrier::Pass(){
    std::unique_lock<std::mutex> lock(mtx);
    if (barrierState){
        inside--;
        if (inside == 0) {
            barrierState = false;
            cv.notify_all();
        } else {
            cv.wait (lock, [&] {return !barrierState; });
        }
    } else {
        inside++;
        if (inside == num_threads) {
            barrierState = true;
            cv.notify_all();
        } else {
            cv.wait(lock, [&] { return barrierState; });
        }
    }
}