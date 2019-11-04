#include <parser/leda/LedaTokenizer.hpp>
#include <istream>
#include <cctype>

using namespace sana;
// possible tokens
// GRAPH_HEADER: STRING newline
//     CONSTRAINT: GRAPH_HEADER IS "LEDA.GRAPH"
// TYPE_HEADER: STRING newline
//     CONSTRAINT: TYPE_HEADER IS bool string int
// GRAPH_DIRECTION_HEADER: ^(-1|-2)$ newline
// NUMBER: [0-9]+
// STRING: [a-zA-Z0-9.]+
// NODE: |{STRING}|
// EDGE: NUMBER NUMBER NUMBER |{STRING}|

LedaTokenizer::LedaTokenizer(std::istream &in):
      in(in), 
      line(0),
      col(0), 
      currentToken(Token(TokenType::STRING, "")) {
}

bool LedaTokenizer::hasNext() {
    return in.eof();
}

Token LedaTokenizer::nextToken() {
    bufferLen = 0;
    char startingToken = skipWhiteSpace();
    if (startingToken == EOF) {
        return currentToken = Token(TokenType::ENDFILE, "");
    } else if (startingToken == '\n') {
        return currentToken = Token(TokenType::NEWLINE, "\n");
    }
    bufferLen++;
    if (startingToken == "|") {
        parseNodeInfo(starting
    }
    /*
    currentToken = inputstream.get();
    return currentToken = inputstream.get();
    */
    return currentToken;
}

char LedaTokenizer::skipWhiteSpace() {
    while (not in.eof()) {
        char c = in.get();
        col++;
        if (not std::isspace(c) or c == '\n') {
            break;
        }
    }
    return c;
}

Token LedaTokenizer::getCurrentToken() {
    return currentToken;
}
