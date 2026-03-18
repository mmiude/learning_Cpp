//
// Created by Mmiud on 9/5/2025.
//

#include "GPIOPin.h"
#include "pico/stdlib.h"
#include <iostream>

GPIOPin::GPIOPin(int pinNr, bool input0, bool pullup0, bool invert0) : pin(pinNr), input(input0), pullUp(pullup0), invert(invert0) {

    gpio_init(pinNr);
    if (input) {
        if (invert0) gpio_set_inover(pinNr, GPIO_OVERRIDE_INVERT);
        gpio_set_dir(pinNr, GPIO_IN);
        gpio_pull_up(pinNr);
    }
    else {
        if (invert0) gpio_set_outover(pinNr, GPIO_OVERRIDE_INVERT);
        gpio_set_dir(pinNr, GPIO_OUT);
    }
    //gpio_init(pinNr);
    stdio_init_all();
}

bool GPIOPin::read() const {
    return gpio_get(pin);
}

bool GPIOPin::operator()() const {
    return read();
}

void GPIOPin::write(bool value) const {
    gpio_put(pin, value);
}

void GPIOPin::operator() (bool value) const {
    write(value);
}

GPIOPin::operator int() const {
    return pin;
}

// parihandler class functions:
Pair::Pair(GPIOPin &button, GPIOPin &led) : button1(button), led1(led), buttonReleased(0){
}

/*bool Pairhandler::setOn() const {
    if (button()) {
        led(true);
        while (button()) sleep_ms(10);
        return true;
    }
    return false;
}*/

void Pair::setOff() const {
    led1(false);
}

void Pair::setOn() const {
    led1(true);
}

bool Pair::checkButton() const {
    return button1();
}

void Pair::setButtonTime() {
    buttonReleased = to_ms_since_boot((get_absolute_time()));
}
bool Pair::waitTime() const {
    if (to_ms_since_boot(get_absolute_time()) - buttonReleased >= 1000) return true;
    return false;
}