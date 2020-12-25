#ifndef SUPPORTEDARGUMENTS_HPP_
#define SUPPORTEDARGUMENTS_HPP_

#include <iostream>
#include <string> 
#include <vector>
#include <array>
#include <unordered_set>

//this should be refactored without global/extern variables -Nil

extern std::vector<std::string> defaultArguments; //static table filled in the cpp file
extern std::vector<std::array<std::string, 6>> supportedArguments; //static table filled in the cpp file

extern std::vector<std::string> stringArgs;
extern std::vector<std::string> doubleArgs;
extern std::vector<std::string> boolArgs;
extern std::vector<std::string> doubleVectorArgs;
extern std::vector<std::string> stringVectorArgs;

class SupportedArguments {
public:
	//validates the fields in supportedArguments and adds them to the Arg vectors. ignores the default values
	static void validateAndAddArguments();

	//Used to generate the help text when ./sana -h or ./sana --help is invoked from command line.
	static void printAllArgumentDescriptions(const std::unordered_set<std::string>& help_args);

private:
	static std::string printItem(const std::array<std::string, 6>& item); //Helper function of printAllArgumentDescriptions() that prints a single argument to the console.
	static std::string formatDescription(const std::string& description); //helper function of printItem() that helps with the formatting of console output.
	static std::string formatWithNewLines(const std::string &item4); //helper function of formatDescription() that outputs a description of an argument on multiple lines when hasNewLines() evaluates to true.
};

#endif /* SUPPORTEDARGUMENTS_HPP_ */