#ifndef MODE_HPP_
#define MODE_HPP_

#include <string>

#include "arguments/ArgumentParser.hpp"
#include "configuration/Configuration.hpp"

namespace sana {
    // Refactored mode
    struct Mode {
        explicit Mode(Configuration configuration);
        virtual void run() = 0;
        virtual ~Mode() {};
    protected:
        Configuration config;
    };
}
class Mode {
public:
    virtual void run(ArgumentParser& args) = 0;
    virtual std::string getName(void) = 0;
    virtual ~Mode() {};
};

#endif /* MODE_HPP_ */
