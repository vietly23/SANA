#ifndef NORMALMODE_HPP_
#define NORMALMODE_HPP_

#include "Graph.hpp"
#include "arguments/ArgumentParser.hpp"
#include "measures/MeasureCombination.hpp"
#include "methods/Method.hpp"
#include "modes/Mode.hpp"

using namespace std;

class NormalMode : public Mode {
public:
    void run(ArgumentParser& args);
    string getName();
    static void createFolders();
};

#endif /* NORMALMODE_HPP_ */
