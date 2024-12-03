#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../utils/file_reader.h"

// Function to check if a report is safe
bool isSafe(const std::vector<int>& report) {
    if (report.size() < 2) {
        return false; // A report with less than 2 numbers cannot be evaluated
    }

    bool isIncreasing = true;
    bool isDecreasing = true;

    for (size_t i = 1; i < report.size(); ++i) {
        int diff = report[i] - report[i - 1];

        // Check if the difference is outside the allowed range [1, 3]
        if (std::abs(diff) < 1 || std::abs(diff) > 3) {
            return false;
        }

        // Check if it's not strictly increasing
        if (diff < 0) {
            isIncreasing = false;
        }

        // Check if it's not strictly decreasing
        if (diff > 0) {
            isDecreasing = false;
        }
    }

    // A report is safe if it is either strictly increasing or strictly decreasing
    return isIncreasing || isDecreasing;
}

int main() {
    // Read input from the input file
    std::vector<std::string> input = readFile("day02/input.txt");

    // Parse input into a 2D vector of integers
    std::vector<std::vector<int>> reports;
    for (const auto& line : input) {
        std::stringstream ss(line);
        std::vector<int> report;
        int num;
        while (ss >> num) {
            report.push_back(num);
        }
        reports.push_back(report);
    }

    // Check each report for safety
    int safeCount = 0;
    for (const auto& report : reports) {
        if (isSafe(report)) {
            ++safeCount;
        }
    }

    // Output the number of safe reports
    std::cout << "Number of safe reports: " << safeCount << std::endl;

    return 0;
}
