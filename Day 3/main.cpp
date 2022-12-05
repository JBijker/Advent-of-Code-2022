#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <numeric>

int letter_value(int n);

int main() {
    std::cout << "Advent of Code DAY 3" << std::endl;
    int score = 0;

    std::vector<std::vector<std::string>> groups = { { } };

    std::ifstream file("../input.txt");
    std::string line;
    if (file.is_open()) {
        std::cout << "File opened" << std::endl;
        while (file) {
            std::getline(file, line);
            if (!line.empty()) {

                if (groups[groups.size() - 1].size() == 3){
                    std::vector<std::string> group = { line };
                    groups.push_back(group);
                } else {
                    groups[groups.size() - 1].push_back(line);
                }

                //Lowercase item types a through z have priorities 1 through  26. | a: 97
                //Uppercase item types A through Z have priorities 27 through 52. | A: 65

                std::string compartment1_string = line.substr(0, line.length() / 2);
                std::string compartment2_string = line.substr(line.length() / 2, line.length());

                std::sort(compartment1_string.begin(), compartment1_string.end());
                std::sort(compartment2_string.begin(), compartment2_string.end());
                std::vector<char> compartment1(compartment1_string.begin(), compartment1_string.end());
                std::vector<char> compartment2(compartment2_string.begin(), compartment2_string.end());

                std::vector<int> v_intersection;
                std::set_intersection(compartment1.begin(), compartment1.end(),
                                      compartment2.begin(), compartment2.end(),
                                      std::back_inserter(v_intersection));
                for(int n : v_intersection) {
                    std::cout << (char)n << ' ';
                    score += letter_value(n);
                    std::cout << n << ' ';
                    break; //Only once
                }
                std::cout << ", line 1: " << std::endl;

            }
        }
    }

    std::cout << "Total score: " << score << std::endl;

    int badge_score = 0;

    for (auto group: groups) {
        std::sort(group[0].begin(), group[0].end());
        std::sort(group[1].begin(), group[1].end());
        std::sort(group[2].begin(), group[2].end());
        std::vector<char> elf1(group[0].begin(), group[0].end());
        std::vector<char> elf2(group[1].begin(), group[1].end());
        std::vector<char> elf3(group[2].begin(), group[2].end());

        std::vector<int> v_intersection;
        std::vector<int> v_intersection2;

        std::set_intersection(elf1.begin(), elf1.end(),
                              elf2.begin(), elf2.end(),
                              std::back_inserter(v_intersection));

        std::set_intersection(v_intersection.begin(), v_intersection.end(),
                              elf3.begin(), elf3.end(),
                              std::back_inserter(v_intersection2));

        int n = v_intersection2[0];
        std::cout << "Group badge found: " << (char) n << ":" << letter_value(n) << std::endl;
        badge_score += letter_value(n);

    }

    std::cout << "Groups: " << groups.size() << ", " << badge_score << std::endl;

    return 0;
}

int letter_value (int letter) {
    int n = letter;
    if (n >= 97) { // a
        n -= 96;
    } else {
        n -= 38;
    }
    return n;
}