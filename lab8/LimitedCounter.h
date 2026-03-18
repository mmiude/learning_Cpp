
#ifndef LIMITEDCOUNTER_H
#define LIMITEDCOUNTER_H

#include "Counter.h"

class LimitedCounter : public Counter {
public:
    LimitedCounter(int initialValue, int upperLimit);
    void inc() override;
    void dec() override;
    operator int() override;
private:
    int currentValue;
    int limit;
};

#endif //LIMITEDCOUNTER_H
