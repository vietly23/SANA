#ifndef ANALYSISMODE_HPP_
#define ANALYSISMODE_HPP_

#include "graph/Graph.hpp"
#include "arguments/ArgumentParser.hpp"
#include "modes/Mode.hpp"

class AnalysisMode : public Mode {
public:
    void run(ArgumentParser& args);
    string getName();
};

#endif /* ANALYSISMODE_HPP_ */
