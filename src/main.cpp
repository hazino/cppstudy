#include <iostream>
#include <csignal>
#include "message.h"

using namespace std;

void signalHanler(int signum) {
    (void)signum;
    cout << "signal:" << signum << endl;
}

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    signal(SIGINT, signalHanler);
    signal(SIGTERM, signalHanler);

    cout << "Hello World!" << endl;
    return 0;
}