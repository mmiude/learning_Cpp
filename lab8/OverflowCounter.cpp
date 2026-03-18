//
// Created by Mmiud on 9/12/2025.
//

#include "OverflowCounter.h"

OverflowCounter::OverflowCounter(int initialValue, int upperLimit) : currentValue(initialValue), limit(upperLimit) {

}

void OverflowCounter::inc() {
    if (currentValue == limit) currentValue = 0;
    else currentValue++;
}

void OverflowCounter::dec() {
    if (currentValue == 0) currentValue = limit;
    else currentValue--;
}

OverflowCounter::operator int() {
    return currentValue;
}
