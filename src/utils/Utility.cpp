#include "utils/Utility.hpp"

#include <random>
#include <sstream>
#include "spdlog/spdlog.h"

using namespace sana;

RandomUtility::RandomUtility(seed initialSeed): initialSeed(initialSeed) {
    this->randomBitGenerator = std::mt19937((unsigned int)initialSeed);
}

int RandomUtility::randomInteger(int low, int high) {
    thread_local std::uniform_int_distribution<> dis(low, high);
    return dis(randomBitGenerator);
}

double RandomUtility::randomDouble() {
    thread_local std::uniform_real_distribution<> realDis(0, 1);
    return realDis(randomBitGenerator);
}

std::vector<std::string> StreamUtility::splitIntoWords(std::istream &in) const {
    std::vector<std::string> result;
    for (std::string line; std::getline(in, line);) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            if (not word.empty() and word.back() == '\r') {
                word.pop_back();
            }
            result.push_back(word);
        }
    }
    return result;
}
