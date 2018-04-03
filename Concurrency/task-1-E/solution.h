#pragma once

#include <vector>
#include <thread>
#include <atomic>
#include <array>

class petersonMutex {
public:
    petersonMutex() {
        want[0].store(false);
        want[1].store(false);
        victim.store(0);
    }
    void lock(std::size_t t) {
        want[t].store(true);
        victim.store(t);
        while (want[1 - t].load() && victim.load() == t) {
            std::this_thread::yield();
        }
    }
    void unlock(std::size_t t) {
        want[t].store(false);
    }
private:
    std::array<std::atomic<bool>, 2> want;
    std::atomic <std::size_t> victim;
};

class TreeMutex {
private:
    std::vector<petersonMutex> tournamentTree;
    void  extraUnlock(size_t current_index);
public:
    TreeMutex(std::size_t n_threads) : tournamentTree(n_threads) {}
    void lock(std::size_t current_thread);
    void unlock(size_t current_thread);
};
void TreeMutex::extraUnlock(std::size_t current_index) {
    std::size_t index = current_index / 2;
    if (index == 0)
        return;
    else {
        extraUnlock(index);
        tournamentTree[index].unlock(current_index % 2);
    }
}
void TreeMutex::lock(std::size_t current_thread) {
    std::size_t index =(tournamentTree.size()+ current_thread) / 2;
    std::size_t select =(tournamentTree.size() + current_thread) % 2;
    while (index != 0) {
        tournamentTree[index].lock(select);
        select = index % 2;
        index = index / 2;
    }
}
void TreeMutex::unlock(size_t current_thread) {
    extraUnlock(tournamentTree.size() + current_thread);
}