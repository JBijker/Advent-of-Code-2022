#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <regex>

auto get_numbers(const std::string& sentence) {
    std::regex number_regex(R"((\d+))", std::regex_constants::ECMAScript);
    std::vector<std::string> strings(std::sregex_token_iterator(sentence.begin(), sentence.end(), number_regex),
                                     std::sregex_token_iterator());

    std::vector<int> numbers;
    std::transform(strings.begin(), strings.end(), std::back_inserter(numbers),
                   [&](const std::string& s) {
                       return stoi(s);
                   });
    return numbers;
}

int main() {
    std::cout << "Advent of Code DAY 5" << std::endl;

    bool parsing_stacks = true;
    int number_of_stacks = 9;
    std::vector<std::vector<char>> stacks = { };
    for (int i = 0; i < number_of_stacks; ++i) {
        stacks.emplace_back();
    }

    std::ifstream file("../input.txt");
    std::string line;
    if (file.is_open()) {
        std::cout << "File opened" << std::endl;
        while (file) {
            std::getline(file, line);
            if (line.empty()) continue;
            if (parsing_stacks && line[1] == '1'){
                parsing_stacks = false;
                continue;
            }
            if (parsing_stacks) {
                for (int i = 0; i < number_of_stacks; ++i) {
                    char item = line[i * 4 + 1];
                    if (item != ' ') {
                        stacks[i].push_back(item);
                    }
                }
            } else {
                std::vector<int> numbers = get_numbers(line);
                std::cout << "moving " << numbers[0] << " from " << numbers[1] << " to " << numbers[2] << ": ";
                std::vector<char>* from = &stacks.at(numbers[1]-1);
                std::vector<char>* to = &stacks.at(numbers[2]-1);
                for (int i = 0; i < numbers[0]; ++i) {
                    char item = (*from)[(numbers[0]-1)-i];
                    to->insert(to->begin(), item);
                    from->erase(from->begin() + (numbers[0]-1)-i);
                }
                std::cout << std::endl;
            }

        }
    }
    std::cout << "Top of stacks: ";

    for (int i = 0; i < number_of_stacks; ++i) {
        std::cout << stacks[i][0];
    }

    return 0;
}