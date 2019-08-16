#include <random>
#include <sstream>
#include <fstream>
#include <iterator>

#include <sana/Random.hpp>
#include <sana/Utils.hpp>

RandomNumberGenerator randObj;
mt19937 gen(randObj.GetSeed());
ranlux24_base fastGen(randObj.GetSeed());

int Utils::RandInt(int low, int high) {
    uniform_int_distribution <> dis(low,high);
    return dis(fastGen);
}

std::vector< std::vector<std::string> > Utils::fileToStringsByLines(const std::string &fileName) {
    checkFileExists(fileName);
    std::ifstream ifs(fileName.c_str());
    std::vector<std::vector<std::string>> result(0);
    string token;
    while(getline(ifs,token)) {
        std::istringstream iss(token);
       std::vector<string> words;
       copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), back_inserter(words)) ;
        result.push_back(words);
    }
    ifs.close();
    return result;
}

void Utils::checkFileExists(const string &fileName) {
    std::stringstream errorMsg;
    std::ifstream fileCheck;
    fileCheck.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        fileCheck.open(fileName);
    } catch (std::ifstream::failure &e) {
        errorMsg << "File " << fileName << " not found/or couldn't open" << endl;
        throw runtime_error(errorMsg.str().c_str());
    } catch (...) {
        errorMsg << "An unknown exception has occurred while opening " << fileName << endl;
        throw runtime_error(errorMsg.str().c_str());
    }
    fileCheck.close();
}




