#include <iostream>
#include <utility>
#include <map>

int main() {

    std::string userInput;
    std::map<std::string, int> myMap;
    int age = 0;

    while (true) {
        std::cout << R"(Enter name or "stop" or "print": )";
        std::cin >> userInput;

        if (userInput == "stop") break;

        if (userInput == "print") {
            for (const auto& [key, value] : myMap) std::cout << key << " : " << value << std::endl;
        }

        else {
            std::cout << "Enter integer: ";
            std::cin >> age;
            auto p1 = std::make_pair(userInput, age);
            myMap.insert(p1);
        }
    }

    return 0;
}