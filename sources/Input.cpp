#include "Input.hh"
#include "Lexer.hh"
#include "Parser.hh"
#include "AvmCore.hh"

Input::Input(eFlag flag) : _flag(flag)
{
    std::string buf;
    AvmCore     core;

    while (std::getline(std::cin, buf, '\n'))
    {
        cleanLine(buf);
        if (buf == ";;")
            break;
        else if (buf.length() > 0)
        {
            if (_flag == INTERACTIVE)
            {
                Lexer       lex(this->epurLine(buf));
                Parser      pars(lex.getTokens(), INTERACTIVE);
                core.run(pars.getInstructions());
            }
            else
                _buf += this->epurLine(buf);
        }
    }
    if (_flag == INTERACTIVE)
      core.check();
}

Input::Input(const std::string &file) : _flag(NORMAL)
{
    std::ifstream   fd(file.c_str());
    std::string     buf;

    if (!fd.is_open())
        throw Error(std::string("Can't open file : " + file));
    while (std::getline(fd, buf, '\n'))
    {
        cleanLine(buf);
        _buf += this->epurLine(buf);
    }
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

std::string Input::epurLine(const std::string &line) const
{
    std::string     ret = line.substr(0, line.find(';', 0));
    size_t	    pos = 0;

    while ((pos = ret.find("##", pos)) != ret.npos)
        ret.replace(pos, 2, "");
    return ret + " ## ";
}

void Input::cleanLine(std::string &line) const
{
    while (line[0] == ' ')
        line.erase(0, 1);
    while (line[line.length() - 1] == ' ')
        line.erase(line.length() - 1, 1);
}

std::ostream    &operator<<(std::ostream &os, const Input &other)
{
    if (os == std::cout)
        os << "Input : " << std::endl << std::endl << other.getBuf() << std::endl << "End";
    return os;
}

////////////////////
// Input::Error   //
////////////////////
Input::Error::Error(const std::string &error) : AvmException(error)
{
}

const std::string   Input::Error::getMessage(void) const
{
    std::stringstream   ss;

    ss << "Input error : " << this->getError();
    return ss.str();
}

