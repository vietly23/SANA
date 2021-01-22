
#include "Mode.hpp"

#include <utility>

sana::Mode::Mode(Configuration configuration):config(std::move(configuration)) {
}
