//
// Created by Mmiud on 9/11/2025.
//
#include <iostream>
#include "Person.h"

Person::Person(const char* name) : name(name) {
}

void Person::identity() const {
    std::cout << "My name is: " << name << std::endl;
}

void Person::interrogate() {

}

// Spy class

Spy::Spy(const char* name, const char* alias, const int resistance) : Person(name), alias(alias), resistance(resistance) {
}

void Spy::set_identity(const char* newAlias) {
    alias = newAlias;
}

void Spy::identity() const {
    if (resistance == 0) {
        Person::identity();
        std::cout << "My alias is: " << alias << std::endl;
    } else std::cout << "My name is: " << alias << std::endl;
}

void Spy::interrogate() {
    if (resistance > 0) resistance--;
}