#include "AbstractVm.hh"

#ifndef EXCEPTIONS_HH
#define EXCEPTIONS_HH

class   AvmException : public std::exception
{
private:
    const std::string   _error;
public:
    AvmException(const std::string &error);
    ~AvmException(void) throw() {}
    const std::string   &getError(void) const;
    virtual const std::string   getMessage(void) const;
};
#endif // EXCEPTIONS_HH
