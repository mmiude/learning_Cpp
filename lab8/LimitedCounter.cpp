//
// Created by Mmiud on 9/12/2025.
//

#include "LimitedCounter.h"

LimitedCounter::LimitedCounter(int initialValue, int upperLimit) : currentValue(initialValue), limit(upperLimit) {
}

void LimitedCounter::inc() {
    if (currentValue < limit) currentValue++;
}

void LimitedCounter::dec() {
  if (currentValue > 0) currentValue--;
}

LimitedCounter::operator int() {
    return currentValue;
}


