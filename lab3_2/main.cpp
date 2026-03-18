#include <iostream>
#include "class.h"

int main() {
    int value;

    RunningAverage avg(5);

    while (true) {
        std::cout << "Enter numbers and enter zero to stop: ";
        std::cin >> value;

        if (value != 0) {
            avg.add_value(value);
            std::cout << "Current average is: " << avg.get_average() << std::endl;
        }
        else {
            std::cout << "Current average is: " << avg.get_average() << std::endl;
            break;
        }
    }

    return 0;
}