#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "item_class.h"

void printInfo(std::vector<Item> &list);

int main() {

    std::vector<Item> itemList;
    std::string line;
    int weight;
    double price;
    int count;
    int index;

    while (true) {
        std::cout << R"(Enter name or ("stop" / "json"): )";
        getline(std::cin >> std::ws, line);

        if (line == "stop") break;

        if (line == "json") {
            Item it;
            std::cout << "Enter JSON: ";
            if (std::cin >> it) {
                std::cout << "json no errors." << std::endl;
                itemList.push_back(it);
            }
            else {
                std::cout << "invalid JSON format. Try again." << std::endl;
                std::cin.clear();
                getline(std::cin, line);
            }

        }
        else {
            std::cout << "Enter weight (g): ";
            std::cin >> weight;
            std::cout << "Enter price (e): ";
            std::cin >> price;
            std::cout << "Enter count: ";
            std::cin >> count;
            itemList.emplace_back(line,weight, price, count);
        }
        line.clear();
    }

    printInfo(itemList);

    std::cout << "Choose item to change by entering the index number: ";
    std::cin >> index;
    std::cout << "Enter new price: ";
    std::cin >> price;

    itemList[index-1].setPrice(price);

    printInfo(itemList);

    return 0;
}

void printInfo(std::vector<Item> &list) {
    std::sort(list.begin(), list.end());

    for (int i = 0; i < list.size(); i++) {
        std::cout << "[" << i+1 << "] " << list[i] << std::endl;
    }

    std::cout << "Net worth of the stock: ";

    double total = 0;
    for (const auto& it : list) {
        total += (it.getPrice() * it.getCount());
    }

    std::cout << total << " euros" << std::endl;
}