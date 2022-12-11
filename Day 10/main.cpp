#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <regex>
#include <sstream>
#include <map>
#include <thread>

std::vector<std::string> lines;
void draw(int cycle, int x) {
    int pixel = (cycle - 1);
    int row = floor(pixel / 40);
    pixel = pixel - row * 40;
    if (abs(x - pixel) < 2) {
        if (lines.size() - 1 < row)lines.emplace_back("........................................");
        lines[row][pixel] = '#';
    }
}

void endCycle(int *cycle, int x, int *total_strength) {
    (*cycle)++;
    if (*cycle == 20 || ((*cycle - 20) % 40 == 0)){
        int strength = *cycle * x;
        (*total_strength) += strength;
//        std::cout << "cycle " << *cycle << " strength: " << strength << " (x: " << x << ")" << std::endl;
    }
    draw(*cycle, x);
}


int main() {
    std::cout << "Advent of Code DAY 10" << std::endl;

    std::ifstream file("../input.txt");
    std::string line;
    lines.emplace_back("........................................");

    int cycle = 0;
    int x = 1;
    int total_strength = 0;

    if (file.is_open()) {
        std::cout << "File opened" << std::endl;
        while (file) {
            std::getline(file, line);
            if (line.empty()) continue;

            char command[4];
            int d;
            char line_char[line.length() + 1];
            strcpy(line_char, line.c_str());
            sscanf(line_char, "%4s %d", &command, &d);

            if (command[0] == 'n') {
                endCycle(&cycle, x, &total_strength);
            } else {
                //Add operation
                for (int i = 0; i < 2; ++i) {
                    endCycle(&cycle, x, &total_strength);
                }
                x += d;
            }

//            std::cout << "command " << command << " d " << d << std::endl;

        }
    }
    std::cout << "cycles: " << cycle << ", x: " << x <<  std::endl;
    std::cout << "total_strength: " << total_strength << std::endl;

    for (auto & row : lines) {
        std::cout << row << std::endl;
    }


    return 0;
}




