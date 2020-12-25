#include <fstream>
#include <sstream>
#include <vector>

//same as utils, but for templated functions
//it is included from utils. because it contains templates, it has no header itself

template <typename T>
std::string toStringWithPrecision(const T val, const int n) {
    std::ostringstream oss;
    oss.precision(n);
    oss << std::fixed << val;
    return oss.str();
}
