#include <iostream>
#include "Spy.h"

// Spy class

Spy::Spy(const char* name, const char* alias, const int resistance) : Person(name), alias(alias), resistance(resistance) {
}

void Spy::set_identity(const char* newAlias) {
    alias = newAlias;
}

void Spy::identity() {
    if (resistance == 0) {
        Notify();
        Person::identity();
        std::cout << "My alias is: " << alias << std::endl;
    } else std::cout << "My name is: " << alias << std::endl;
}

void Spy::interrogate() {
    if (resistance > 0) --resistance;
}

void Spy::Attach(Observer *o) {
    judges.push_back(o);
}

void Spy::Notify() {
    for (const auto j : judges) {
        if (j != nullptr) j->Update();
    }
}


