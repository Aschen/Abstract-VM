#include "Exceptions.hh"

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
