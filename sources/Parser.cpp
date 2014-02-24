#include "Parser.hh"
#include "Exceptions.hh"


Parser::Parser(const std::vector<Token> &tokenList) : _tokenList(tokenList)
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
    this->parse();
}

Parser::Parser(const Parser &cpy) : _tokenList(cpy._tokenList), _types(cpy._types)
{
    this->parse();
}

void Parser::parse(void)
{
    std::vector<Token>::const_iterator  it = _tokenList.begin();

    while ((it = this->readInstructionLine(it)) != _tokenList.end())
        ;
    if (!this->readExit())
        throw ParserException("Unable to find \"exit\" instruction.");
}

TokenCIterator &Parser::readInstructionLine(TokenCIterator &it)
{
    it = this->readInstruction(it);
    this->readSeparator(it);
    ++it;
    return it;
}

TokenCIterator &Parser::readInstruction(TokenCIterator &it)
{
    eInstrType      instrType;
    eOperandType    valueType = Null;
    std::string     value = "";

    if (it->first > VINSTR)
    {
        if (it != _tokenList.begin())
            throw ParserException("Expected Instruction token", it->second, (it - 1)->second);
        else
            throw ParserException("Expected Instruction token", it->second);
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
    return it;
}

eOperandType Parser::readValueType(TokenCIterator &it)
{
    if (it->first != NTYPE && it->first != DTYPE) // Si it = _token.begin() fail ??
        throw ParserException("Expected ValueType token", it->second, (it - 1)->second);
    return (_types.find(it->second))->second;
}

std::string Parser::readValue(TokenCIterator &it, eOperandType type)
{
    std::string value;

    if (it->first != NUMBER && it->first != DECIMAL)
        throw ParserException("Expected Value token", it->second, (it - 1)->second);
    if (type <= Int32 && it->first != NUMBER)
        throw ParserException("Expected Number value", it->second, (it - 1)->second);
    if (type >= Float && it->first != DECIMAL)
        throw ParserException("Expected Decimal value", it->second, (it - 1)->second);
    value = it->second;
    return value;
}

void Parser::readSeparator(TokenCIterator &it)
{
    if (it->first != SEP)
        throw ParserException("Expected Separator token", it->second, (it - 1)->second);
}

bool Parser::readExit(void)
{
    std::vector<Instruction>::iterator    it = _instrList.begin();

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
