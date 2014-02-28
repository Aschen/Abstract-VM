#include "Lexer.hh"

Lexer::Lexer(const std::string &input) : _input(input), _inputStream(input)
{
    this->_tokens["push"] = VINSTR;
    this->_tokens["assert"] = VINSTR;
    this->_tokens["pop"] = INSTR;
    this->_tokens["dump"] = INSTR;
    this->_tokens["add"] = INSTR;
    this->_tokens["sub"] = INSTR;
    this->_tokens["mul"] = INSTR;
    this->_tokens["div"] = INSTR;
    this->_tokens["mod"] = INSTR;
    this->_tokens["print"] = INSTR;
    this->_tokens["exit"] = INSTR;
    this->_tokens["##"] = SEP;
    this->_tokens["int8"] = NTYPE;
    this->_tokens["int16"] = NTYPE;
    this->_tokens["int32"] = NTYPE;
    this->_tokens["float"] = DTYPE;
    this->_tokens["double"] = DTYPE;
    this->_tokens["entier"] = NUMBER;
    this->_tokens["decimal"] = DECIMAL;
    this->_tokens["unknown"] = UNKNOWN;
    this->_aff[VINSTR] = "VINSTR";
    this->_aff[INSTR] = "INSTR";
    this->_aff[SEP] = "SEP";
    this->_aff[NTYPE] = "NTYPE";
    this->_aff[DTYPE] = "DTYPE";
    this->_aff[NUMBER] = "NUMBER";
    this->_aff[DECIMAL] = "DECIMAL";
    this->_aff[UNKNOWN] = "UNKNOWN";
    if (_input.length())
        this->tokenize();
}

Lexer::Lexer(const Lexer &cpy) : _input(cpy._input), _inputStream(cpy._input), _tokenList(cpy._tokenList), _tokens(cpy._tokens)
{
    if (_input.length())
        this->tokenize();
}

void                Lexer::dumpTokens(void)
{
    std::vector<Token>::const_iterator    it = _tokenList.begin();

    while (it != _tokenList.end())
    {
        std::cout << "[" << _aff[it->first] << "]-> ";
        std::cout << it->second << std::endl;
        ++it;
    }
}

std::vector<Token> Lexer::getTokens(void) const
{
    return _tokenList;
}

void    Lexer::tokenize(void)
{
    std::string     tok;

    _line = 1;
    _word = 1;
    while (_inputStream >> tok)
    {
        if (this->readInstr(tok))
            ;
        else if (this->readValue(tok))
            ;
        else
            throw Error(_line, _word, "Unknown token '" + tok + "'");
        _word++;
    }
}

bool Lexer::readInstr(const std::string &tok)
{
    TokenMap::iterator  it = _tokens.find(tok);

    if (it != _tokens.end())
    {
        _tokenList.push_back(Token(it->second, it->first));
        if (it->second == SEP)
        {
            _line++;
            _word = 0;
        }
        return true;
    }
    return false;
}

bool Lexer::readValue(const std::string &tok)
{
    std::string         type;
    std::string         value;
    size_t  	        pos = tok.find('(');
    TokenMap::iterator  it;

    type = tok.substr(0, pos);
    if ((it = _tokens.find(type)) == _tokens.end())
        throw Error(_line, _word, "Unknown Value Type '" + tok.substr(0, tok.find('(')) + "'");
    if (pos == tok.npos || tok.find(')', pos) == tok.npos)
        throw Error(_line, _word, "Missing '(' or ')' near " + tok);
    if (tok.find(')', pos) + 1 != tok.length())
        throw Error(_line, _word, "Reading garbage after value. ( '" + tok.substr(tok.find(')', pos) + 1) + "')");
    value = tok.substr(pos + 1, tok.find(')', pos + 1) - pos - 1);
    if (value.length() == 0)
        throw Error(_line, _word, "Invalid empty value '" + tok + "'");
    _tokenList.push_back(Token(it->second, type));
    if (this->readDecimal(value))
        _tokenList.push_back(Token(DECIMAL, cleanValue(value)));
    else if (this->readNumber(value))
        _tokenList.push_back(Token(NUMBER, cleanValue(value)));
    else
    {
      _tokenList.pop_back();
      throw Error(_line, _word, "Invalid value '" + tok.substr(pos) + "'");
    }
    return true;
}

bool Lexer::readNumber(const std::string &tok) const
{
    unsigned int    i = 0;

    if (!ISNUM(tok[i]) && tok[i++] != '-')
        return false;
    while (i < tok.length())
    {
        if (!ISNUM(tok[i++]))
            return false;
    }
    return true;
}


bool Lexer::readDecimal(const std::string &tok) const
{
    unsigned int    i = 0;

    if (count(tok.begin(), tok.end(), '.') != 1 )
        return false;
    if (!ISNUM(tok[i]) && tok[i++] != '-')
        return false;
    while (i < tok.length())
    {
        if (!ISNUM(tok[i]) && tok[i] != '.')
            return false;
        i++;
    }
    return true;
}

std::string &Lexer::cleanValue(std::string &str) const
{
    while (str[0] == '0')
        str.erase(0, 1);
    if (str.find('.') != str.npos)
        while (str[str.length() - 1] == '0')
            str.erase(str.length() - 1, 1);
    return str;
}


/////////////////////
// Lexer::Error    //
/////////////////////
Lexer::Error::Error(const unsigned int line, const unsigned int col, const std::string &error)
    : AvmException(error), _line(line), _col(col)
{
}

const std::string Lexer::Error::getMessage(void) const
{
    std::stringstream   ss;

    ss << "Lexer Error : On line " << _line << " word " << _col << " : " << this->getError();
    return ss.str();
}

