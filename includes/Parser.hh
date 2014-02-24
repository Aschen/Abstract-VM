#ifndef PARSER_HH
#define PARSER_HH

#include "AbstractVm.hh"

class   Parser
{
private:
    typedef std::map<eOperandType, std::string> affValue;
    typedef std::map<eInstrType, std::string>   affInstr;
    affInstr                    _affInstr;
    affValue                    _affValue;
    const std::vector<Token>    _tokenList;
    std::vector<Instruction>    _instrList;
    TypeMap                     _types;
    InstructionMap              _instructions;
public:
    Parser(const std::vector<Token> &tokenList);
    ~Parser(void) {}
    Parser(const Parser &cpy);

    void            dumpInstruction(void);
private:
    void            parse(void);
    TokenCIterator  &readInstructionLine(TokenCIterator &it);
    TokenCIterator  &readInstruction(TokenCIterator &it);
    eOperandType    readValueType(TokenCIterator &it);
    std::string     readValue(TokenCIterator &it, eOperandType type);
    void            readSeparator(TokenCIterator &it);
    bool            readExit(void);
};


#endif // PARSER_HH
