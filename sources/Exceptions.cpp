#include "Exceptions.hh"

/////////////////////
// LexerException //
/////////////////////
LexerException::LexerException(const unsigned int line, const unsigned int col, const std::string error)
    : AvmException(error), _line(line), _col(col)
{
}

const std::string LexerException::getMessage(void) const
{
    std::stringstream   ss;

    ss << "Lexer Error : On line " << _line << " word " << _col << " : " << this->getError() << std::endl;
    return ss.str();
}

////////////////////
// InputException //
////////////////////
InputException::InputException(const std::string error) : AvmException(error)
{
}

const std::string   InputException::getMessage(void) const
{
    return "Input error : " + this->getError();
}
////////////////////
// AvmException   //
////////////////////
AvmException::AvmException(const std::string error) : _error(error)
{
}

const std::string AvmException::getMessage(void) const
{
    return _error;
}

const std::string AvmException::getError(void) const
{
    return _error;
}

////////////////////
// ParserException//
////////////////////
ParserException::ParserException(const std::string error) : AvmException(error), _token("")
{
}

ParserException::ParserException(const std::string error, const std::string &token, const std::string &prevToken) : AvmException(error), _token(token), _prevToken(prevToken)
{
}

ParserException::ParserException(const std::string error, const std::string &token) : AvmException(error), _token(token), _prevToken("")
{
}

const std::string ParserException::getMessage(void) const
{
    if (_token.length() > 0)
    {
        if (_prevToken.length() > 0)
            return "Parser error : " + this->getError() + " after '" + _prevToken + "' (have '" + _token + "')";
        else
            return "Parser error : " + this->getError() + " at beginning" + " (have '" + _token + "')";
    }
    return "Parser error : " + this->getError() + ".";
}
