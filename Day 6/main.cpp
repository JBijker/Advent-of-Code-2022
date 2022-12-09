#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <regex>

int main() {
    std::cout << "Advent of Code DAY 6" << std::endl;

    std::ifstream file("../input.txt");
    std::string line;
    if (file.is_open()) {
        std::cout << "File opened" << std::endl;
        while (file) {
            std::getline(file, line);
            if (line.empty()) continue;

            std::regex regex(R"((\w)(?!\1)(\w)(?!\1)(?!\2)(\w)(?!\1)(?!\2)(?!\3))");
            std::smatch matches;
            std::regex_search(line, matches, regex);

            std::cout << matches.size() << ", " << matches.position();

        }
    }

    return 0;
}





