#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::cout << "Advent of Code DAY 1" << std::endl;
    std::vector<int> elve_calories;
    elve_calories.push_back(0);

    int elve = 0;
    std::ifstream file ("../Day 1/input.txt");
    std::string line;
    if ( file.is_open() ) {
        std::cout << "File opened" << std::endl;
        while ( file ) {
            std::getline (file, line);
            if (line.empty()){
                elve++;
                elve_calories.push_back(0);
                continue;
            }
            int calories = std::stoi(line);
            elve_calories[elve] += calories;
        }
    }

    std::sort(elve_calories.begin(), elve_calories.end());
    std::cout << "Number of elves: " << elve_calories.size() << std::endl;
    std::cout << "LAST elve calories: " << elve_calories.back() << std::endl;

    int number_of_elves_to_add = 3;
    auto result = std::reduce(elve_calories.end() - number_of_elves_to_add, elve_calories.end());
    std::cout << "LAST " << number_of_elves_to_add << " elve calories: " << result << std::endl;

    return 0;
}
