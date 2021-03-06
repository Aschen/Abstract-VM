//
// Limits.cpp for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/rompart
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Tue Feb 25 11:53:36 2014 brunne-r
// Last update Sun Mar  2 11:09:59 2014 brunne-r
//

#include "Limits.hh"

template<typename T>
void		Limits::check(const std::string &value)
{
  T		ivalue;
  std::string	b;
  unsigned int	prec;

  prec = Transform::getStrPrecision(value);
  ivalue = Transform::stringToValue<T>(value);
  Transform::valueToString<T>(ivalue, b, prec);
  if (b != value)
    {
      std::cout << "Precision:" << prec << std::endl;
      std::cout << value << " VS " << b << std::endl;
      if (value[0] == '-')
	throw Limits::Error("underflow");
      else
	throw Limits::Error("overflow");
    }
}

Limits::Error::Error(const std::string &error) : AvmException(error)
{
}

const std::string Limits::Error::getMessage(void) const
{
    std::stringstream   ss;

    ss << "Limit reach : " << this->getError();
    return ss.str();
}

template void Limits::check<int8>(const std::string &value);
template void Limits::check<int16>(const std::string &value);
template void Limits::check<int32>(const std::string &value);
template void Limits::check<float>(const std::string &value);
template void Limits::check<double>(const std::string &value);
