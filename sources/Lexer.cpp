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
    this->_tokens["entier"] = NUMBER; // mettre key vide ? ""
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
    this->tokenize();
}

Lexer::Lexer(const Lexer &cpy) : _input(cpy._input), _inputStream(cpy._input), _tokenList(cpy._tokenList), _tokens(cpy._tokens)
{
    this->tokenize();
}

void                Lexer::dumpTokens(void)
{
    std::vector<Token>::iterator    it = _tokenList.begin();

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
    std::string                 tok;

    _line = 1;
    _word = 1;
    while (_inputStream >> tok)
    {
        if (this->readInstr(tok))
            ;
        else if (this->readValue(tok))
            ;
        else
            throw LexerException(_line, _word, "Unknown token " + tok);
        _word++;
    }
}

bool Lexer::readInstr(const std::string &tok)
{
    TokenMap::iterator  it = _tokens.find(tok);

    if (it != _tokens.end())
    {
//        std::cout << "Add token " << _aff[it->second] << " : " << it->first << std::endl;
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
    unsigned int        pos = tok.find('(');
    TokenMap::iterator  it;

    // SI de la forme 'type(valeur)'
    if (pos != tok.npos && tok.find(')', pos) != tok.npos && tok.find(')', pos) + 1 == tok.length())
    {
        type = tok.substr(0, tok.find('('));
        value = tok.substr(pos + 1, tok.find(')', pos + 1) - pos - 1);
        // SI valeur existe et type existant
        if (value.length() > 0 && (it = _tokens.find(type)) != _tokens.end())
        {
  //          std::cout << "Add token " << _aff[it->second] << " : " << type << std::endl;
            _tokenList.push_back(Token(it->second, type));
            if (this->readNumber(value))
            {
    //            std::cout << "Add token " << _aff[NUMBER] << " : " << value << std::endl;
                _tokenList.push_back(Token(NUMBER, value));
                return true;
            }
            else if (this->readDecimal(value))
            {
      //          std::cout << "Add token " << _aff[DECIMAL] << " : " << value << std::endl;
                _tokenList.push_back(Token(DECIMAL, value));
                return true;
            }
            else
                _tokenList.pop_back();
        }
    }
    return false;
}

bool Lexer::readNumber(const std::string &tok)
{
    unsigned int    i = 0;

    while (i < tok.length())
    {
        if (!ISNUM(tok[i++]))
            return false;
    }
    return true;
}


bool Lexer::readDecimal(const std::string &tok)
{
    unsigned int    i = 0;

    while (i < tok.length())
    {
        if (!ISNUM(tok[i]) && tok[i] != '.')
            return false;
        i++;
    }
    return true;
}
