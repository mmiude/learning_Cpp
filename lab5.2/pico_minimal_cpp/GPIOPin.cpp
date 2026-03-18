
#include "GPIOPin.h"
#include "pico/stdlib.h"

GPIOPin::GPIOPin(const int pinNr, const bool input0, const bool pullup0, const bool invert0) : pin(pinNr), input(input0), pullUp(pullup0), invert(invert0) {

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

    stdio_init_all();
}

bool GPIOPin::read() const {
    return gpio_get(pin);
}

bool GPIOPin::operator()() const {
    return read();
}

void GPIOPin::write(const bool value) const {
    gpio_put(pin, value);
}

void GPIOPin::operator() (const bool value) const {
    write(value);
}

GPIOPin::operator int() const {
    return pin;
}

//-------------------------------------------------

Pair::Pair(const int buttonNr, const int ledNr, const int releaseTime) :
    button1(buttonNr, true, true, true), led1(ledNr, false, false, false), buttonReleased(releaseTime) {
}

void Pair::checkPair() {
    if (button1()) {
        led1(true);
        buttonReleased = to_ms_since_boot((get_absolute_time()));
    }
    else {
        if (led1() && (to_ms_since_boot(get_absolute_time()) - buttonReleased >= 1000)) led1(false);
    }
}

