//
// Created by Mmiud on 9/25/2025.
//

#include <iostream>
#include "ColorObserver.h"

void ColorObserver::Update(std::string & title, int value) {
    std::cout << "Color: " << title << " changed to value: " << value << std::endl;
}