#include "AbstractVm.hh"
#include "Exceptions.hh"

#ifndef PARSER_HH
#define PARSER_HH

class   Parser
{
public:
    class   Error : public AvmException
    {
    private:
        const std::string   _token;
        const std::string   _prevToken;
    public:
        Error(const std::string error);
        Error(const std::string error, const std::string &token, const std::string &prevToken);
        Error(const std::string error, const std::string &token);
        ~Error(void) throw() {}
        const std::string   getMessage(void) const;
    };
private:
    typedef std::map<eOperandType, std::string> affValue;
    typedef std::map<eInstrType, std::string>   affInstr;
    affInstr                    _affInstr;
    affValue                    _affValue;
    const std::vector<Token>    _tokenList;
    std::vector<Instruction>    _instrList;
    TypeMap                     _types;
    InstructionMap              _instructions;
    eFlag                       _flag;
public:
    Parser(const std::vector<Token> &tokenList, eFlag flag);
    ~Parser(void) {}
    Parser(const Parser &cpy);

    void            dumpInstruction(void);
private:
    void            parse(void);
    TokenCIterator  &readInstructionLine(TokenCIterator &it);
    TokenCIterator  &readInstruction(TokenCIterator &it);
    eOperandType    readValueType(TokenCIterator &it);
    std::string     readValue(TokenCIterator &it, eOperandType type);
    TokenCIterator  &readSeparator(TokenCIterator &it);
    bool            readExit(void);
};


#endif // PARSER_HH
