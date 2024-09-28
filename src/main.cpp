#include <iostream>
#include <csignal>
#include "message.h"
#include "manager.h"
using namespace std;

void signalHanler(int signum) {
    (void)signum;
    cout << "signal:" << signum << endl;
    manager::getInstance()->stop();
}
void threadTest() {
    auto manager = manager::getInstance();
    std::cout << "init()" << std::endl;
    manager->init();
    std::cout << "start()" << std::endl;
    manager->start();
    std::cout << "join()" << std::endl;
    manager->join();
    std::cout << "deinit()" << std::endl;
    manager->deinit();
}

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    signal(SIGINT, signalHanler);
    signal(SIGTERM, signalHanler);

    threadTest();

    return 0;
}