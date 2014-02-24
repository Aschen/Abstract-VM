#ifndef LEXER_HH
#define LEXER_HH

#include "AbstractVm.hh"
#include "Exceptions.hh"

#define ISNUM(c)    ((c) >= '0' && (c) <= '9')

class   Lexer
{
private:
    const std::string           _input;
    std::stringstream           _inputStream;
    std::vector<Token>          _tokenList;
    TokenMap                    _tokens;
    std::map<eTokenType, std::string>             _aff;
    unsigned int                _line;
    unsigned int                _word;

public:
    Lexer(const std::string &input);
    ~Lexer(void) {}
    Lexer(const Lexer &cpy);

    void                dumpTokens(void);
    std::vector<Token>  getTokens(void) const;
private:
    void                tokenize(void);
    bool                readInstr(const std::string &tok);
    bool                readValue(const std::string &tok);
    bool                readNumber(const std::string &tok);
    bool                readDecimal(const std::string &tok);
};
// typedef std::pair<eTokenType, std::string>      Token;
// typedef std::map<std::string, eTokenType>       TokenMap;

#endif // LEXER_HH
