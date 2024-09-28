#include <iostream>
#include <thread>
#include <memory>
#include <atomic>

class manager {

public:
    static std::shared_ptr<manager> getInstance() {
        static std::shared_ptr<manager> instance(new manager);
        return instance;
    }
    bool init();
    bool deinit();
    bool start();
    bool stop();
    bool join();
private:
    std::thread t1;
    void t1_thread();
    std::atomic<bool> running_;
};
