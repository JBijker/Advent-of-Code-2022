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

int main() {
    std::cout << "Advent of Code DAY 8" << std::endl;

    std::ifstream file("../input.txt"); //Needs a newline at eof!
    std::string line;
    std::vector<std::string> rows;
    std::vector<std::string> columns;

    if (file.is_open()) {
        std::cout << "File opened" << std::endl;
        while (file) {
            std::getline(file, line);
            if (line.empty()) continue;
            rows.push_back(line);
            for (int i = 0; i < line.length(); ++i) {
                if (columns.size() <= i)columns.emplace_back();
                columns[i] += line[i];
            }
        }
    }

    int count = rows.size() * 2 + (columns.size() - 2) * 2; // edges
    for (int x = 1; x < rows.size() - 1; ++x) {
        for (int y = 1; y < columns.size() - 1; ++y) {
            char height = rows[x][y];
            std::cout << "Tree [" << x << "," << y << "](" << height << ") ";
            if (*max_element(std::begin(rows[x]), std::begin(rows[x]) + y) < height // left
                || *max_element(std::begin(rows[x]) + y + 1, std::end(rows[x])) < height // right
                || *max_element(std::begin(columns[y]), std::begin(columns[y]) + x) < height // top
                || *max_element(std::begin(columns[y]) + x + 1, std::end(columns[y])) < height // bottom
                    ) {
                std::cout << "visible";
                count++;
            }
            std::cout << std::endl;
        }
    }

    int highest_scenic_score = 0;
    for (int x = 0; x < rows.size(); ++x) {
        for (int y = 0; y < columns.size(); ++y) {
            char height = rows[x][y];
            std::cout << "Tree [" << x << "," << y << "](" << height << ") ";
            int right = 0;
            for(std::string::iterator it = rows[x].begin() + y + 1; it < rows[x].end(); ++it) { // to right
                right++;
                if (*it >= height)break;
            }
            int left = 0;
            for(std::string::iterator it = rows[x].begin() + y - 1; it >= rows[x].begin(); --it) { // to left
                left++;
                if (*it >= height)break;
            }
            int bottom = 0;
            for(std::string::iterator it = columns[y].begin() + x + 1; it < columns[y].end(); ++it) { // to bottom
                bottom++;
                if (*it >= height)break;
            }
            int top = 0;
            for(std::string::iterator it = columns[y].begin() + x - 1; it >= columns[y].begin(); --it) { // to top
                top++;
                if (*it >= height)break;
            }
            std::cout << "score " << (top * left * bottom * right);
            if (top * left * bottom * right > highest_scenic_score) {
                highest_scenic_score = (top * left * bottom * right);
            }

            // Alternative, didn't get it to work:
//            auto it = std::find_if (rows[x].begin() + y + 1, rows[x].end() - 1,
//                                    [&height] (const char& c) { return c >= height; });
//            std::cout << " blocked by " << *it << " after " << (it - rows[x].begin() - y);

            std::cout << std::endl;
        }
    }

    std::cout << "Count: " << count << std::endl;
    std::cout << "Highest scenic score: " << highest_scenic_score << std::endl;

    return 0;
}




