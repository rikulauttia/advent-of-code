#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    std::string line;
    std::regex mulRegex("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    std::regex doRegex("\\bdo\\(\\)");
    std::regex dontRegex("\\bdon't\\(\\)");

    bool isEnabled = true;
    long long sum = 0;

    while (std::getline(inputFile, line)) {
        auto mulBegin = std::sregex_iterator(line.begin(), line.end(), mulRegex);
        auto mulEnd = std::sregex_iterator();
        auto doBegin = std::sregex_iterator(line.begin(), line.end(), doRegex);
        auto dontBegin = std::sregex_iterator(line.begin(), line.end(), dontRegex);

        std::sregex_iterator currentMul = mulBegin;
        std::sregex_iterator currentDo = doBegin;
        std::sregex_iterator currentDont = dontBegin;

        while (currentMul != mulEnd || currentDo != std::sregex_iterator() || currentDont != std::sregex_iterator()) {
            if (currentDo != std::sregex_iterator() && (currentMul == mulEnd || currentDo->position() < currentMul->position()) && (currentDont == std::sregex_iterator() || currentDo->position() < currentDont->position())) {
                isEnabled = true;
                ++currentDo;
            } else if (currentDont != std::sregex_iterator() && (currentMul == mulEnd || currentDont->position() < currentMul->position())) {
                isEnabled = false;
                ++currentDont;
            } else if (currentMul != mulEnd) {
                if (isEnabled) {
                    int num1 = std::stoi((*currentMul)[1].str());
                    int num2 = std::stoi((*currentMul)[2].str());
                    sum += num1 * num2;
                }
                ++currentMul;
            }
        }
    }

    inputFile.close();
    std::cout << "The sum of enabled multiplications is: " << sum << std::endl;
    return 0;
}
