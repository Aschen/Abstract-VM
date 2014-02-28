#include "Parser.hh"
#include "Exceptions.hh"


Parser::Parser(const std::vector<Token> &tokenList, eFlag flag) : _tokenList(tokenList), _flag(flag)
{
    _types["int8"] = Int8;
    _types["int16"] = Int16;
    _types["int32"] = Int32;
    _types["double"] = Double;
    _types["float"] = Float;
    _instructions["push"] = PUSH;
    _instructions["assert"] = ASSERT;
    _instructions["pop"] = POP;
    _instructions["dump"] = DUMP;
    _instructions["add"] = ADD;
    _instructions["sub"] = SUB;
    _instructions["mul"] = MUL;
    _instructions["div"] = DIV;
    _instructions["mod"] = MOD;
    _instructions["print"] = PRINT;
    _instructions["exit"] = EXIT;
    _affInstr[PUSH] = "push";
    _affInstr[ASSERT] = "assert";
    _affInstr[POP] = "pop";
    _affInstr[DUMP] = "dump";
    _affInstr[ADD] = "add";
    _affInstr[SUB] = "sub";
    _affInstr[MUL] = "mul";
    _affInstr[DIV] = "div";
    _affInstr[MOD] = "mod";
    _affInstr[PRINT] = "print";
    _affInstr[EXIT] = "exit";
    _affValue[Int8] = "int8";
    _affValue[Int16] = "int16";
    _affValue[Int32] = "int32";
    _affValue[Float] = "float";
    _affValue[Double] = "double";
    _affValue[Null] = "";
    if (!_tokenList.empty())
        this->parse();
}

Parser::Parser(const Parser &cpy) : _tokenList(cpy._tokenList), _types(cpy._types), _flag(cpy._flag)
{
    if (!_tokenList.empty())
        this->parse();
}

void Parser::parse(void)
{
    std::vector<Token>::const_iterator  it = _tokenList.begin();

    while (it->first == SEP)
        ++it;
    while (it != _tokenList.end())
        this->readInstructionLine(it);
    if (_flag == NORMAL)
        if (!this->readExit())
            throw Error("Unable to find \"exit\" instruction.");
}

void Parser::readInstructionLine(TokenCIterator &it)
{
    this->readInstruction(it);
    this->readSeparator(it);
}

void Parser::readInstruction(TokenCIterator &it)
{
    eInstrType      instrType;
    eOperandType    valueType = Null;
    std::string     value = "";

    if (it != _tokenList.end())
    {
        if (it->first > VINSTR)
        {
            if (it != _tokenList.begin())
                throw Error("Expected Instruction token", it->second, (it - 1)->second);
            else
                throw Error("Expected Instruction token", it->second);
        }
        instrType = _instructions[it->second];
        if (it->first == VINSTR)
        {
            ++it;
            valueType = this->readValueType(it);
            ++it;
            value = this->readValue(it, valueType);
        }
        _instrList.push_back(Instruction(instrType, Value(valueType, value)));
        ++it;
    }
}

eOperandType Parser::readValueType(TokenCIterator &it) const
{
    if (it->first != NTYPE && it->first != DTYPE)
        throw Error("Expected ValueType token", it->second, (it - 1)->second);
    return (_types.find(it->second))->second;
}

const std::string Parser::readValue(TokenCIterator &it, eOperandType type) const
{
    std::string value;

    if (it->first != NUMBER && it->first != DECIMAL)
        throw Error("Expected Value token", it->second, (it - 1)->second);
    if (type <= Int32 && it->first != NUMBER)
        throw Error("Expected Number value", it->second, (it - 1)->second);
    if (type >= Float && it->first != DECIMAL)
        throw Error("Expected Decimal value", it->second, (it - 1)->second);
    value = it->second;
    return value;
}

void Parser::readSeparator(TokenCIterator &it) const
{
    if (it != _tokenList.end())
    {
        if (it->first != SEP)
            throw Error("Expected Separator token", it->second, (it - 1)->second);
        while (it->first == SEP)
            ++it;
    }
}

bool Parser::readExit(void) const
{
    std::vector<Instruction>::const_iterator    it = _instrList.begin();

    while (it != _instrList.end())
    {
        if (it->first == EXIT)
            return true;
        ++it;
    }
    return false;
}

void Parser::dumpInstruction(void)
{
    std::vector<Instruction>::iterator  it = _instrList.begin();

    while (it != _instrList.end())
    {
        std::cout << " - " << _affInstr[it->first] << " " << _affValue[it->second.first] << " " << it->second.second << "" << std::endl;
        ++it;
    }
}

const std::vector<Instruction>	Parser::getInstructions(void) const
{
  return _instrList;
}

////////////////////
// Parser::Error  //
////////////////////
Parser::Error::Error(const std::string &error) : AvmException(error), _token("")
{
}

Parser::Error::Error(const std::string &error, const std::string &token, const std::string &prevToken) : AvmException(error), _token(token), _prevToken(prevToken)
{
}

Parser::Error::Error(const std::string &error, const std::string &token) : AvmException(error), _token(token), _prevToken("")
{
}

const std::string Parser::Error::getMessage(void) const
{
    std::stringstream   ss;

    if (_token.length() > 0)
    {
        if (_prevToken.length() > 0)
            ss << "Parser error : " << this->getError() << " after '" << _prevToken << "' (have '" << _token << "')";
        else
            ss << "Parser error : " << this->getError() << " at beginning" << " (have '" << _token << "')";
        return ss.str();
    }
    ss << "Parser error : " << this->getError() << ".";
    return ss.str();
}
