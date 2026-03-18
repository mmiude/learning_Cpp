#include <iostream>
#include <vector>


int main() {

    std::vector<int> numbers;
    int numberAmount;

    std::cout << "How many numbers do you want to enter: ";
    std::cin >> numberAmount;

    for (int i = 0; i < numberAmount; i++) {
        int number;
        std::cout << "Enter nr[" << i+1 << "]: ";
        std::cin >> number;
        numbers.push_back(number);
    }

    std::cout << "You entered: ";
    //for (auto number: numbers) std::cout << number << " ";
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i];
        if (i < numbers.size()-1) std::cout << ", ";
    }
    std::cout << std::endl;

    return 0;
}