#ifndef ARGUMENTPARSER_HPP
#define ARGUMENTPARSER_HPP

#include <map>
#include <string>
#include <vector>
#include "configuration/Configuration.hpp"

using namespace std;

class ArgumentParser {
public:
    /* initializes the arguments and stores them in the maps below
    hierarchy of preference: command line > optional file > default values > base values
    optional file: the user can optionally put *as first argument* a file with values
    default values: from SupportedArguments::defaultArguments
    base values: numbers (0), strings (""), vectors (empty), bool (false) */

    sana::Configuration parseArguments(int argc, char* argv[]);
    map<string, string> strings;
    map<string, double> doubles;
    map<string, bool> bools;
    map<string, vector<double>> doubleVectors;
    map<string, vector<string>> stringVectors;

    vector<string> originalArgv; //argv but in vector format
};

#endif /* ARGUMENTPARSER_HPP */


