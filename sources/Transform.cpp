//
// Transform.cpp for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Fri Feb 21 12:45:27 2014 brunne-r
// Last update Sun Mar  2 11:17:13 2014 brunne-r
//

#include "Transform.hh"

unsigned int	Transform::getStrPrecision(const std::string &value)
{
  size_t	dot;

  dot = value.find(".");
  if (dot != std::string::npos)
    {
      return ((value.size() - 1) - dot);
    }
  else
    return 0;
}

template<typename T>
T Transform::stringToValue(const std::string &str)
{
  T			value(0);
  std::stringstream	strm(str);
  short			inter(0);

  strm.precision(Transform::getStrPrecision(str));
  if (sizeof(T) > 1)
    strm >> value;
  else
    {
      strm >> inter;
      value = T(inter);
    }
  return value;
}

template int8	Transform::stringToValue(const std::string &str);
template int16	Transform::stringToValue(const std::string &str);
template int32	Transform::stringToValue(const std::string &str);
template float	Transform::stringToValue(const std::string &str);
template double	Transform::stringToValue(const std::string &str);

template<typename U>
void Transform::valueToString(const U &value, std::string &dest, const unsigned int &precision)
{
  std::ostringstream	strm;
  
  strm.precision(precision);
  strm << std::fixed;
  if (sizeof(U) > 1)
    strm << value;
  else
    strm << short(value);
  dest = strm.str();
}

template void Transform::valueToString(const int8 &value, std::string &dest, const unsigned int &precision);
template void Transform::valueToString(const int16 &value, std::string &dest, const unsigned int &precision);
template void Transform::valueToString(const int32 &value, std::string &dest, const unsigned int &precision);
template void Transform::valueToString(const float &value, std::string &dest, const unsigned int &precision);
template void Transform::valueToString(const double &value, std::string &dest, const unsigned int &precision);
