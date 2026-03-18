#include <iostream>

void modifyString(std::string &sentence, std::string word);

int main() {

    std::string userString;
    std::string userWord;

    while (true) {

        std::cout << "Enter a string: ";
        getline(std::cin >> std::ws, userString);

        std::cout << "Enter a character or \"stop\": ";
        std::cin >> userWord;

        if (userWord == "stop") break;

        modifyString(userString, userWord);
        std::cout << userString << std::endl;

    }

    return 0;
}

void modifyString(std::string &sentence, std::string word) {
    for (auto &character : sentence) {
        if (character == word[0]) character = '_';
    }
}

