#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

int findXMASAmount(const vector<string>& data) {
    int amount = 0;

    for (size_t i = 0; i < data.size(); i++) {
        regex pattern("X");
        auto begin = sregex_iterator(data[i].begin(), data[i].end(), pattern);
        auto end = sregex_iterator();

        for (auto it = begin; it != end; ++it) {
            int x = it->position();

            if (i >= 3) {
                for (int j = -1; j <= 1; j++) {
                    try {
                        if (data[i - 1][x + j] == 'M' &&
                            data[i - 2][x + 2 * j] == 'A' &&
                            data[i - 3][x + 3 * j] == 'S') {
                            amount++;
                        }
                    } catch (out_of_range&) {}
                }
            }

            if (x >= 3) {
                if (data[i][x - 1] == 'M' &&
                    data[i][x - 2] == 'A' &&
                    data[i][x - 3] == 'S') {
                    amount++;
                }
            }

            if (x <= (int)data[i].length() - 4) {
                if (data[i][x + 1] == 'M' &&
                    data[i][x + 2] == 'A' &&
                    data[i][x + 3] == 'S') {
                    amount++;
                }
            }

            if (i <= data.size() - 4) {
                for (int j = -1; j <= 1; j++) {
                    try {
                        if (data[i + 1][x + j] == 'M' &&
                            data[i + 2][x + 2 * j] == 'A' &&
                            data[i + 3][x + 3 * j] == 'S') {
                            amount++;
                        }
                    } catch (out_of_range&) {}
                }
            }
        }
    }

    return amount;
}

int main() {
    ifstream file("input.txt");
    vector<string> data;
    string line;

    if (!file) {
        cerr << "Error: Cannot open input.txt" << endl;
        return 1;
    }

    while (getline(file, line)) {
        data.push_back(line);
    }

    file.close();

    int amount = findXMASAmount(data);
    cout << "Answer is " << amount << endl;

    return 0;
}
