#include "mbed.h"
#include <chrono>

Thread t1;
Thread t2;

void Moo(){
    while (true){
        printf("Moo\n");
        ThisThread::sleep_for(std::chrono::seconds(1));
    }
}

void Meow(){
    while (true){
        printf("Meow\n");
        ThisThread::sleep_for(std::chrono::seconds(2));
    }
}

int main(){
    t1.start(Moo);
    t2.start(Meow);

    t1.join();
    t2.join();
}

