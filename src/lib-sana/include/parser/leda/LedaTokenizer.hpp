#ifndef SANA_LEDA_TOKENIZER
#define SANA_LEDA_TOKENIZER

#include <istream>
#include <string>
#include <array>

namespace sana {
    
    enum class TokenType { NEWLINE, STRING, NODE_INFO, ENDFILE, };

    struct Token {
        TokenType type;
        std::string value;
        Token(TokenType type, std::string value): type(type), value(value) {};

        // Used mainly for easy unit-testing
        bool operator==(const Token& other) const {
            return type == other.type and value.compare(other.value) == 0;
        }

    private:
        Token() {};
        std::array<char, 4096> buffer;
        unsigned int bufferLen = 0;
    };

    // TODO: Support Unicode 
    class LedaTokenizer {
    public:
        LedaTokenizer(std::istream &in);
        Token getCurrentToken();
        Token nextToken();
        bool hasNext();
    private:
        char skipWhiteSpace();
        std::istream &in;
        Token currentToken;
        unsigned int line;
        unsigned int col;
    };

}
#endif
