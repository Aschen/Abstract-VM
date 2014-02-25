#include <fstream>
#include "AbstractVm.hh"

#ifndef INPUT_HH
#define INPUT_HH


class   Input
{
private:
    std::string   _buf;
    eFlag         _flag;
public:
    Input(eFlag flag);
    Input(const std::string &file);
    ~Input(void);
    Input   &operator=(const Input &cpy);

    std::string     getBuf(void) const;
private:
    std::string     epurLine(std::string line);
};

std::ostream    &operator<<(std::ostream &os, const Input &other);

#endif // INPUT_HH
