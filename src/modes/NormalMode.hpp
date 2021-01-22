#ifndef NORMALMODE_HPP_
#define NORMALMODE_HPP_

#include "graph/Graph.hpp"
#include "graph/GraphLoader.hpp"
#include "arguments/ArgumentParser.hpp"
#include "measures/MeasureCombination.hpp"
#include "methods/Method.hpp"
#include "modes/Mode.hpp"

using namespace std;

class NormalMode : public Mode, public sana::Mode {
public:
    NormalMode();
    NormalMode(sana::Configuration config, GraphLoader graphLoader);
    ~NormalMode();
    void run() override;
    void run(ArgumentParser& args);
    string getName();
    static void createFolders();
private:
    GraphLoader graphLoader;
};

#endif /* NORMALMODE_HPP_ */
