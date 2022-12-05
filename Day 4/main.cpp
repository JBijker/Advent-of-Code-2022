#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <numeric>
#include <regex>

auto get_numbers(const std::string& sentence) {
    std::regex number_regex("(\\d+)", std::regex_constants::ECMAScript);
    std::vector<std::string> strings(std::sregex_token_iterator(sentence.begin(), sentence.end(), number_regex),
                                     std::sregex_token_iterator());
    std::vector<int> numbers;
    std::transform(strings.begin(), strings.end(), std::back_inserter(numbers),
                   [&](std::string s) {
                       return stoi(s);
                   });
    return numbers;
}

int main() {
    std::cout << "Advent of Code DAY 4" << std::endl;
    int fully_overlapping_pairs = 0;
    int partially_overlapping_pairs = 0;

    std::vector<std::vector<std::string>> groups = { { } };

    std::ifstream file("../input.txt");
    std::string line;
    if (file.is_open()) {
        std::cout << "File opened" << std::endl;
        while (file) {
            std::getline(file, line);
            if (!line.empty()) {
                std::vector<int> numbers = get_numbers(line);

                // Alternative to regex: */
                int elve1_from, elve1_to, elve2_from, elve2_to;
                char line_char[line.length() + 1];
                strcpy(line_char, line.c_str());
                sscanf (line_char, "%d-%d,%d-%d", &elve1_from, &elve1_to, &elve2_from, &elve2_to);

                std::cout << "Test: " << elve1_from << " == " << numbers[0] << std::endl;

                if ( (numbers[0] >= numbers[2] && numbers[1] <= numbers[3]) ||
                 (numbers[2] >= numbers[0] && numbers[3] <= numbers[1])) {
                    fully_overlapping_pairs += 1;
                }

                if (!(numbers[1] < numbers[2] || numbers[0] > numbers[3])) {
                    partially_overlapping_pairs += 1;
                }


            }
        }
    }

    std::cout << "Total fully overlapping pairs: " << fully_overlapping_pairs << std::endl;
    std::cout << "Total partially overlapping pairs: " << partially_overlapping_pairs << std::endl;


    return 0;
}