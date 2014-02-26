#include <fstream>
#include "Exceptions.hh"

#ifndef INPUT_HH
#define INPUT_HH


class   Input
{
public:
    class   Error : public AvmException
    {
    public:
        Error(const std::string &error);
        ~Error(void) throw() {}
        const std::string   getMessage(void) const;
    };
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
