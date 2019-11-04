#ifndef SANA_LEDA_PARSER
#define SANA_LEDA_PARSER

#include <istream>
#include <parser/GraphParser.hpp>
#include <graph/BinaryGraph.hpp>

class LedaParser : public GraphParser {
    virtual BinaryGraph parse(std::istream inputstream);
};
#endif
