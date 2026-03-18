//
// Created by Mmiud on 9/5/2025.
//

#ifndef GPIOPIN_H
#define GPIOPIN_H
#include <cstdint>

class GPIOPin {
public:
    explicit GPIOPin(int pinNr, bool input0 = true, bool pullup0 = true, bool invert0 = false);
    GPIOPin(const GPIOPin &) = delete;
    bool read() const;
    bool operator() () const;
    void write(bool value) const;
    void operator() (bool) const;
    operator int() const;

private:
    int pin;
    bool input;
    bool pullUp;
    bool invert;
};

class Pair {
public:
    Pair(GPIOPin &button, GPIOPin &led);
    //bool setOn() const;
    void setOff() const;
    void setOn() const;
    bool checkButton() const;
    void setButtonTime();
    bool waitTime() const;
private:
    GPIOPin &button1;
    GPIOPin &led1;
    uint64_t buttonReleased;
};


#endif //GPIOPIN_H
