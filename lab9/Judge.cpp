//
// Created by Mmiud on 9/16/2025.
//
#include <iostream>
#include "Judge.h"

Judge::Judge(const char* name) : Person(name) {
}

void Judge::Update() {
    std::cout << "[";
    Person::identity();
    std::cout << "I'm sending a spy to prison!]" << std::endl;
}