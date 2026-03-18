//
// Created by Mmiud on 9/11/2025.
//
#include <iostream>
#include "Person.h"

Person::Person(const char* name) : name(name) {
}

void Person::identity() {
    std::cout << "My name is: " << name << std::endl;
}

void Person::interrogate() {

}

