#include "AbstractVm.hh"

#ifndef EXCEPTIONS_HH
#define EXCEPTIONS_HH

class   AvmException : public std::exception
{
private:
    const std::string   _error;
public:
    AvmException(const std::string error);
    ~AvmException(void) throw() {}
    const std::string   getError(void) const;
    virtual const std::string   getMessage(void) const;
};

class   LexerException : public AvmException
{
private:
    const unsigned int    _line;
    const unsigned int    _col;
public:
    LexerException(const unsigned int line, const unsigned int col, const std::string error);
    ~LexerException(void) throw() {}
    const std::string   getMessage(void) const;
};

class   InputException : public AvmException
{
public:
    InputException(const std::string error);
    ~InputException(void) throw() {}
    const std::string   getMessage(void) const;
};

class   ParserException : public AvmException
{
private:
    const std::string   _token;
    const std::string   _prevToken;
public:
    ParserException(const std::string error);
    ParserException(const std::string error, const std::string &token, const std::string &prevToken);
    ParserException(const std::string error, const std::string &token);
    ~ParserException(void) throw() {}
    const std::string   getMessage(void) const;
};

#endif // EXCEPTIONS_HH
