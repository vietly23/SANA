#ifndef SANA_PARSER_INTERFACE
#define SANA_PARSER_INTERFACE

#include <istream>
#include <graph/BinaryGraph.hpp>

class GraphParser {
public:
    virtual BinaryGraph parse(std::istream inputstream);
    virtual ~GraphParser() = 0;
};
#endif
