#include <iostream>
#include "pico/stdlib.h"
#include "GPIOPin.h"

int main() {

    // button - led pairs
    Pair bl1(7, 22);
    Pair bl2(8, 21);
    Pair bl3(9, 20);

    std::cout << "BOOT" << std::endl;

    while (true) {
        bl1.checkPair();
        bl2.checkPair();
        bl3.checkPair();
        sleep_ms(10);
    }
}