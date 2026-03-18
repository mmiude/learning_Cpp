#include <iostream>
#include <algorithm>
#include "UniqueRng.h"

void test_generator(UniqueRng ur, int count);

int main() {
    UniqueRng randGen(5, 13);
    test_generator(randGen, 6);
    test_generator(randGen, 9);
    test_generator(randGen, 13);

    UniqueRng randGen2(1, 35);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 70);
}

void test_generator(UniqueRng ur, const int count) {
    std::vector<int> numbers;

    std::cout << "Generating numbers: " << std::endl;
    try {
        const auto gb = std::back_inserter(numbers);
        std::generate_n(gb, count,  ur);
    } catch (std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        std::cout << "Tried to generate " << count << " random numbers. Got only " << numbers.size() << std::endl;
    }
    for (const auto nr : numbers) std::cout << nr << std::endl;
    std::cout << "End of generator" << std::endl;
}
