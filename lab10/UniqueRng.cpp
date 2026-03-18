//
// Created by Mmiud on 9/16/2025.
//
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include "UniqueRng.h"
#include <iostream>

UniqueRng::UniqueRng(int minValue, int maxValue) : min(minValue), max(maxValue) {
    srand(time(nullptr));
}

int UniqueRng::operator() () {
    int number;

    do {
        if (numbers.size() == (max-min+1)) {
            throw std::runtime_error("Unable to produce unique random number.");
        }
        number = min + (rand() % (max-min+1));
    } while (std::find(numbers.begin(), numbers.end(), number) != numbers.end());

    numbers.push_back(number);
    return number;
}