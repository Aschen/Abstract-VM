#include "Input.hh"
#include "Exceptions.hh"

Input::Input(void)
{
    std::string buf;
    bool        flag = true;

    while (flag)
    {
        std::getline(std::cin, buf, '\n');
        if (buf == ";;")
            flag = false;
        else if (buf.length() > 0)
            _buf += this->epurLine(buf);
    }
}

Input::Input(const std::string &file)
{
    std::ifstream   fd(file.c_str());
    std::string     buf;

    if (!fd.is_open())
        throw InputException(std::string("Can't open file : " + file));
    while (std::getline(fd, buf, '\n'))
        if (buf.length() > 0)
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
    std::string ret = line.substr(0, line.find(';', 0));
    unsigned int    pos = 0;

    while ((pos = ret.find("##", pos)) != ret.npos)
        ret.replace(pos, 2, "");
    if (ret.length() > 0)
        return ret + " ## ";
    return ret;
}

std::ostream    &operator<<(std::ostream &os, const Input &other)
{
    if (os == std::cout)
        os << "Input : " << std::endl << std::endl << other.getBuf() << std::endl << "End";
    return os;
}
