#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "house.h"

int main() {
    std::vector<Apartment> apartments;

    auto house1 = House("Code road 15", 300.0, 900000.0);
    auto house2 = House("Candy lane 29", 400.0, 950000.0);

    apartments.emplace_back(house1, 1, 25, 450);
    apartments.emplace_back(house1, 2, 56, 750);
    apartments.emplace_back(house1, 3, 90, 1200);
    apartments.emplace_back(house2, 4, 20, 400);
    apartments.emplace_back(house2, 5, 56, 880);
    apartments.emplace_back(house2, 6, 100, 2200);
    apartments.emplace_back(house2, 7, 32, 580);

    std::sort(apartments.begin(), apartments.end());

    for (auto &a : apartments) {
       a.printInfo();
        std::cout << std::endl;
    }

    return 0;
}