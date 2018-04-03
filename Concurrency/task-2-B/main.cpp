#include <thread>
#include "solution_semaphore.h"

const size_t steps = 20;
int main() {
    Robot robot;
    std::thread left_thread([&robot] {
        for (size_t i = 0; i < steps; ++i)
            robot.StepLeft();
    });
    std::thread right_thread([&robot] {
        for (size_t i = 0; i < steps; ++i)
            robot.StepRight();
    });
    left_thread.join();
    right_thread.join();
    return 0;
}