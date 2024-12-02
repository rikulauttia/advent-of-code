#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include "../utils/file_reader.h"

int main() {
    std::vector<std::string> input = readFile("day01/input.txt");

    // Vectors to store left and right lists
    std::vector<int> left, right;

    // Parse input and split into left and right lists
    for (const auto& line : input) {
        size_t space_pos = line.find(' ');
        int left_num = std::stoi(line.substr(0, space_pos));
        int right_num = std::stoi(line.substr(space_pos + 1));
        left.push_back(left_num);
        right.push_back(right_num);
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    // Calculate total distance
    int total_distance = 0;
    for (size_t i = 0; i < left.size(); ++i) {
        total_distance += std::abs(left[i] - right[i]);
    }

    std::cout << "Total Distance: " << total_distance << std::endl;

    return 0;
}
