//
// Created by Mmiud on 9/12/2025.
//

#ifndef OVERFLOWCOUNTER_H
#define OVERFLOWCOUNTER_H

#include "Counter.h"

class OverflowCounter : public Counter {
public:
    OverflowCounter(int initialValue, int upperLimit);
    void inc() override;
    void dec() override;
    operator int() override;
private:
    int currentValue;
    int limit;
};


#endif //OVERFLOWCOUNTER_H
