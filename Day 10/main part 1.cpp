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

void draw(std::vector<int> head, std::vector<int> tail, std::map<std::string, int> tail_visited) {

    std::cout << "\x1B[2J\x1B[H";
    int width = 300;
    int height = 70;
    for (int y = -height; y < height; ++y) {
        for (int x = -width; x < width; ++x) {
            if (tail[0] == x && tail[1] == y) {
                std::cout << "T";
            } else if (head[0] == x && head[1] == y) {
                std::cout << "H";
            } else if (tail_visited[std::to_string(x) + "." + std::to_string(y)] == 1){
                std::cout << "#";
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }

}

int main() {
    std::cout << "Advent of Code DAY 9" << std::endl;

    std::ifstream file("../input.txt");
    std::string line;
    std::vector<int> head(2, 0);
    std::vector<int> tail(2, 0);
    std::map<std::string, int> tail_visited;

    int l = 0;

//    bool run = true;
//    while(run) {
//        char direction;
//        std::cin >> direction;
//        switch (direction) {
//            case 'd':
//                head[0]++;
//                break;
//            case 'a':
//                head[0]--;
//                break;
//            case 's':
//                head[1]++;
//                break;
//            case 'w':
//                head[1]--;
//                break;
//            default:
//                run = false;
//        }
//        // move tail
//        if (abs(head[0] - tail[0]) > 1 && abs(head[1] - tail[1]) > 0
//            || abs(head[0] - tail[0]) > 0 && abs(head[1] - tail[1]) > 1) {
//            tail[0] += tail[0] > head[0] ? -1 : 1;
//            tail[1] += tail[1] > head[1] ? -1 : 1;
//        } else if (abs(head[0] - tail[0]) > 1) {
//            tail[0] += tail[0] > head[0] ? -1 : 1;
//        } else if (abs(tail[1] - head[1]) > 1) {
//            tail[1] += tail[1] > head[1] ? -1 : 1;
//        }
//
//        tail_visited[std::to_string(tail[0]) + std::to_string(tail[1])] = 1;
//        draw(head, tail, tail_visited);
//    }

    if (file.is_open()) {
        std::cout << "File opened" << std::endl;
        while (file) {
            l++;
            std::getline(file, line);
            if (line.empty()) continue;

            char direction;
            int steps;
            char line_char[line.length() + 1];
            strcpy(line_char, line.c_str());
            sscanf(line_char, "%c %d", &direction, &steps);

            for (int i = 0; i < steps; ++i) {

//                std::cout << "pos: <" << head[0] << ", " << head[1] << ">" << " <" << tail[0] << ", " << tail[1] << ">"
//                          << std::endl;

                // move head
                switch (direction) {
                    case 'R':
                        head[0]++;
                        break;
                    case 'L':
                        head[0]--;
                        break;
                    case 'D':
                        head[1]++;
                        break;
                    case 'U':
                        head[1]--;
                        break;
                }
                // move tail
                if (abs(head[0] - tail[0]) > 1 && abs(head[1] - tail[1]) > 0
                    || abs(head[0] - tail[0]) > 0 && abs(head[1] - tail[1]) > 1) {
                    tail[0] += tail[0] > head[0] ? -1 : 1;
                    tail[1] += tail[1] > head[1] ? -1 : 1;
                } else if (abs(head[0] - tail[0]) > 1) {
                    tail[0] += tail[0] > head[0] ? -1 : 1;
                } else if (abs(tail[1] - head[1]) > 1) {
                    tail[1] += tail[1] > head[1] ? -1 : 1;
                }

                tail_visited[std::to_string(tail[0]) + "." + std::to_string(tail[1])] = 1;
//                std::cout << "pos: <" << head[0] << ", " << head[1] << ">" << " <" << tail[0] << ", " << tail[1] << "> tail visited: "
//                << std::to_string(tail[0]) + "." + std::to_string(tail[1]) << std::endl;
//                std::cout << "last step: " << (i+1) << "/" << steps << " x " << direction << std::endl;
//                std::cout << l << std::endl;

//                std::this_thread::sleep_for(std::chrono::milliseconds(l < 10000 ? 10 : 5000)); //168

            }

        }
    }

//    draw(head, tail, tail_visited);
    std::cout << "head: <" << head[0] << ", " << head[1] << ">" << std::endl;
    std::cout << "tail: <" << tail[0] << ", " << tail[1] << ">" << std::endl;
    std::cout << "tail_visited: " << tail_visited.size() << std::endl;

    //2743 too low
    //2756

    return 0;
}




