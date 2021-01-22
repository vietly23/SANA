#ifndef MODESELECTOR_HPP_
#define MODESELECTOR_HPP_

#include <memory>

#include "ArgumentParser.hpp"
#include "modes/Mode.hpp"

namespace modeSelector {

//returns whether there exists a mode with name 'name'
bool validMode(string name);

Mode* selectMode(ArgumentParser& args);

} //modeSelector namespace
namespace sana::mode {
    std::unique_ptr<Mode> selectMode(const sana::Configuration& configuration);
}
#endif /* MODESELECTOR_HPP_ */
