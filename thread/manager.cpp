#include "manager.h"

bool manager::init() {
    std::lock_guard<std::mutex> mg(lock_);
    initialized_ = true;
    return true;
}

bool manager::deinit() {
    std::lock_guard<std::mutex> mg(lock_);
    return true;
}

bool manager::start() {
    std::lock_guard<std::mutex> mg(lock_);
    running_ = true;
    t1 = std::thread(&manager::t1_thread, this);
    return true;
}

bool manager::stop() {
    std::lock_guard<std::mutex> mg(lock_);
    if(!t1.joinable()) {
        std::cout << " thread is stop" << std::endl;
        return false;
    }
    running_ = false;
    return true;
}

bool manager::join() {
    std::unique_lock<std::mutex> mg(lock_);
    if(!initialized_) {
        std::cout << "not initialized" << std::endl;
        return false;
    }
    mg.unlock();
    if(t1.joinable()) {
        t1.join();
    }
    return true;
}

void manager::t1_thread() {
    while(running_) {
        
    }
}