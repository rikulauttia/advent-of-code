#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main() {
    // Open the input file
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "Error: Could not open input file!" << endl;
        return 1;
    }

    string line;
    long long sum = 0;

    // Define the regex pattern for valid "mul(X,Y)" instructions
    regex mulPattern(R"(mul\((\d{1,3}),(\d{1,3})\))");

    // Read each line from the file
    while (getline(inputFile, line)) {
        auto words_begin = sregex_iterator(line.begin(), line.end(), mulPattern);
        auto words_end = sregex_iterator();

        // Iterate through matches
        for (auto i = words_begin; i != words_end; ++i) {
            smatch match = *i;
            int x = stoi(match[1].str());
            int y = stoi(match[2].str());
            sum += x * y;
        }
    }

    cout << "Total Sum: " << sum << endl;

    // Close the file
    inputFile.close();
    return 0;
}