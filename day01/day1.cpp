#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
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

    // Build a frequency map for the right list
    std::unordered_map<int, int> right_freq;
    for (const auto& num : right) {
        right_freq[num]++;
    }

    // Calculate the similarity score
    int similarity_score = 0;
    for (const auto& num : left) {
        if (right_freq.count(num)) {
            similarity_score += num * right_freq[num];
        }
    }

    std::cout << "Similarity Score: " << similarity_score << std::endl;

    return 0;
}
