//
// Created by Mmiud on 9/16/2025.
//

#ifndef UNIQUERNG_H
#define UNIQUERNG_H

#include <vector>


class UniqueRng {
public:
    UniqueRng(int minValue, int maxValue);
    int operator()();
private:
    std::vector<int> numbers;
    int min;
    int max;
};


#endif //UNIQUERNG_H
