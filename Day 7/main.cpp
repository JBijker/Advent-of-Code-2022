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


std::string implode(std::vector<std::string> current_path) {
    const char *const delim = "/";
    std::ostringstream current_path_string;
    std::copy(current_path.begin(), current_path.end(),
              std::ostream_iterator<std::string>(current_path_string, delim));
    return current_path_string.str();
}

int main() {
    std::cout << "Advent of Code DAY 7" << std::endl;

    std::ifstream file("../input.txt");
    std::string line;
    std::vector<std::string> current_path;
    std::map<std::string, long> directory_sizes;

    if (file.is_open()) {
        std::cout << "File opened" << std::endl;
        while (file) {
            std::getline(file, line);
            if (line.empty()) continue;
            std::cout << line << std::endl;

            if (line.substr(0, 3) == "dir") {
                continue;
            } else if (line[0] == '$') {
                if (line.substr(2, 2) == "cd") {
                    auto dir = line.substr(5);
                    if (dir == "..") {
                        current_path.pop_back();
                    } else {
                        current_path.push_back(dir);
                    }

                    auto current_path_string = implode(current_path);
                    std::cout << current_path_string << std::endl;
                }
            } else {
                //Add file sizes to paths

                for (int i = 1; i <= current_path.size(); ++i) {
                    auto current_path_string = implode(std::vector<std::string>(current_path.begin(), current_path.begin() + i));

                    char line_chars[line.length() + 1];
                    strcpy(line_chars, line.c_str());
                    long size;
                    sscanf(line_chars, "%ld", &size);

                    std::cout << size << std::endl;
                    directory_sizes[current_path_string] += size;

                    std::cout << directory_sizes[current_path_string] << std::endl;
                }
            }
        }
    }

    long sum_at_most_100000 = 0;
    long size_of_smallest_directory_to_delete = 999999999;
    long used_space = directory_sizes["//"];
    std::cout << "used_space :: " << used_space << std::endl;

    auto it = directory_sizes.begin();
    // Iterate over the map using Iterator till end.
    while (it != directory_sizes.end()) {
        // Accessing KEY from element pointed by it.
        std::string word = it->first;
        // Accessing VALUE from element pointed by it.
        long size = it->second;
//        std::cout << word << " :: " << size << std::endl;
        // Increment the Iterator to point to next entry
        it++;

        if (size <= 100000)sum_at_most_100000 += size;
        if ((70000000 - used_space + size) > 30000000 && size < size_of_smallest_directory_to_delete) {
            size_of_smallest_directory_to_delete = size;
        }
    }

    std::cout << "Sum: " << sum_at_most_100000 << std::endl;
    std::cout << "size_of_smallest_directory_to_delete: " << size_of_smallest_directory_to_delete << std::endl;

    return 0;
}




