#include "manager.h"

bool manager::init() {
    return true;
}

bool manager::deinit() {
    return true;
}

bool manager::start() {
    running_ = true;
    t1 = std::thread(&manager::t1_thread, this);
    return true;
}

bool manager::stop() {
    if(!t1.joinable()) {
        std::cout << " thread is stop" << std::endl;
        return false;
    }
    running_ = false;
    return true;
}

bool manager::join() {
    if(t1.joinable()) {
        t1.join();
    }
    return true;
}

void manager::t1_thread() {
    while(running_) {
        
    }
}