#ifndef INPUT_HH
#define INPUT_HH

#include <fstream>
#include <sstream>
#include "AbstractVm.hh"

class   Input
{
private:
    std::string   _buf;
public:
    Input(void);
    Input(const std::string &file);
    ~Input(void);
    Input   &operator=(const Input &cpy);

    std::string     getBuf(void) const;
private:
    std::string     epurLine(std::string line);
};

std::ostream    &operator<<(std::ostream &os, const Input &other);

#endif // INPUT_HH
