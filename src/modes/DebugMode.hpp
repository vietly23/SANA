#ifndef DEBUGMODE_HPP_
#define DEBUGMODE_HPP_

#include "Graph.hpp"
#include "arguments/ArgumentParser.hpp"
#include "modes/Mode.hpp"

class DebugMode : public Mode {
public:
    void run(ArgumentParser& args);
    std::string getName(void);
};

#endif /* DEBUGMODE_HPP_ */
