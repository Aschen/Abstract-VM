#include "Input.hh"
#include "Lexer.hh"
#include "Parser.hh"
#include "Exceptions.hh"

Input::Input(eFlag flag) : _flag(flag)
{
    std::string buf;

    while (1)
    {
        std::getline(std::cin, buf, '\n');
        if (buf == ";;" || (_flag == INTERACTIVE && buf == "exit"))
            break;
        else if (buf.length() > 0)
        {
            if (_flag == INTERACTIVE)
                Parser(Lexer(this->epurLine(buf)).getTokens(), INTERACTIVE).dumpInstruction();
            else
                _buf += this->epurLine(buf);
        }
    }
}

Input::Input(const std::string &file) : _flag(NORMAL)
{
    std::ifstream   fd(file.c_str());
    std::string     buf;

    if (!fd.is_open())
        throw InputException(std::string("Can't open file : " + file));
    while (std::getline(fd, buf, '\n'))
        _buf += this->epurLine(buf);
    fd.close();
}

Input::~Input(void)
{
}

Input &Input::operator =(const Input &cpy)
{
    if (this != &cpy)
        _buf = cpy._buf;
    return *this;
}

std::string Input::getBuf(void) const
{
    return _buf;
}

std::string Input::epurLine(std::string line)
{
    std::string     ret = line.substr(0, line.find(';', 0));
    unsigned int    pos = 0;

    while ((pos = ret.find("##", pos)) != ret.npos)
        ret.replace(pos, 2, "");
    return ret + " ## ";
}

std::ostream    &operator<<(std::ostream &os, const Input &other)
{
    if (os == std::cout)
        os << "Input : " << std::endl << std::endl << other.getBuf() << std::endl << "End";
    return os;
}
