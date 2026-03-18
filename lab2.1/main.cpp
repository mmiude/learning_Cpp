#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>
#include <string>

int main() {

    std::string stop;
    int number;
    std::vector<int> numbers;
    std::string line;

    while (true) {

        std::cout << "Enter a line with numbers or \"stop\": ";
        getline(std::cin, line);

        std::istringstream sin(line);

        while (sin >> number) numbers.push_back(number);
        sin.clear();

        if (sin >> stop) {
            if (stop.find("stop") == 0) break;
        }

        int total = accumulate(numbers.begin(), numbers.end(), 0);

        std::cout << "total of "<< numbers.size() << " numbers is: " << total << std::endl;
        numbers.clear();
    }

    return 0;
}