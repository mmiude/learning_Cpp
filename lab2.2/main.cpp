#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


void printTerminal(auto pl, std::vector<std::string> &names);
void writeFile(auto pl, std::vector<std::string> &names);

int main() {

    std::string line;
    std::string name;
    std::vector<std::string> directoryNames;

    while (true) {

        std::cout << "Enter directory names or blank line to stop: ";
        getline(std::cin, line);
        if (line.empty()) break;

        std::istringstream sin(line);
        while (sin >> name) directoryNames.push_back(name);

        std::filesystem::path pl;
        for (const auto& dir : directoryNames) {
            pl /= dir;
        }
        create_directories(pl);
        pl /= "result.txt";

        printTerminal(pl, directoryNames);
        writeFile(pl,directoryNames);

        directoryNames.clear();
    }

    return 0;
}


void printTerminal(auto pl, std::vector<std::string> &names) {
    std::cout << "Absolute path: " << std::filesystem::absolute(pl) << std::endl;
    for (auto dir : names) std::cout << dir << std::endl;
    std::cout << "Relative path: " << std::filesystem::relative(pl) << std::endl;
}

void writeFile(auto pl, std::vector<std::string> &names) {
    std::ofstream outFile(pl, std::ofstream::app);
    if (!outFile.is_open()) {
        std::cout << "Error while opening the file." << std::endl;
    }
    outFile << "Absolute path: " << std::filesystem::absolute(pl) << std::endl;
    for (auto dir : names) outFile << dir << std::endl;
    outFile << "Relative path: " << std::filesystem::relative(pl) << std::endl;
}

