#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::cout << "Advent of Code DAY 1" << std::endl;
    int score = 0;

    std::ifstream file("../input.txt");
    std::string line;
    if (file.is_open()) {
        std::cout << "File opened" << std::endl;
        while (file) {
            std::getline(file, line);
            if (!line.empty()) {
                int opponent_shape = (unsigned char) line[0] - 64;
//                int own_shape = (unsigned char) line[2] - 87; // PART 1
                int desired_outcome = (unsigned char) line[2] - 89; //lose -1, draw -, wind +1
                int own_shape = (((opponent_shape - 1) + desired_outcome) % 3) + 1;
//                if (own_shape == 4)own_shape = 1;
//                if (own_shape == 0)own_shape = 3;

                int _score = own_shape;

                std::string what[4] = {"", "rock", "paper", "scissors"};

                if (own_shape == opponent_shape) {
                    // tie
                    _score += 3;
                } else if ((own_shape - opponent_shape == 1) ||
                           (own_shape == 1 && opponent_shape == 3)) {
                    // win
                    _score += 6;
                }

                score += _score;

                std::cout << line << "; " << own_shape << ":" << what[own_shape] << " <> " << what[opponent_shape] << ": " << _score << std::endl;

            }
        }
    }

    std::cout << "Total score: " << score << std::endl;

    return 0;
}

// Part 2 correct: 14060