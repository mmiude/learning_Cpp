#include <iostream>
#include <vector>
#include "pico/stdlib.h"
#include "GPIOPin.h"

int main() {
    std::vector<Pair> blPairs;
    // set GPIO pins
    GPIOPin led1(22, false, false, false);
    GPIOPin led2(21, false, false, false);
    GPIOPin led3(20, false, false, false);
    GPIOPin button1(7, true, true, true);
    GPIOPin button2(8, true, true, true);
    GPIOPin button3(9, true, true, true);

    blPairs.emplace_back(button1, led1);
    blPairs.emplace_back(button2, led2);
    blPairs.emplace_back(button3, led3);

    std::cout << "BOOT" << std::endl;

    while (true) {
        for (auto &bl : blPairs) {
            if (bl.checkButton()) {
                bl.setOn();
                bl.setButtonTime();
            }
            else {
                if (bl.waitTime())  bl.setOff();
            }
            sleep_ms(10);
        }
    }
}