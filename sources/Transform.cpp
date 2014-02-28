//
// Transform.cpp for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Fri Feb 21 12:45:27 2014 brunne-r
// Last update Fri Feb 28 14:47:49 2014 brunne-r
//

#include "Transform.hh"

unsigned int	Transform::getStrPrecision(const std::string &value)
{
  size_t	dot;

  dot = value.find(".");
  if (dot != std::string::npos)
    {
      return (value.size() - dot);
    }
  else
    return 0;
}

template<typename S>
unsigned int	Transform::getPrecision(const S &value)
{
  size_t	trunc, it(10), i(0);
  S		cut, rest, tmp(0);

  trunc = size_t(value);
  cut = trunc;
  rest = value - cut;
  if (rest == 0)
    return 0;
  while (value - cut > std::numeric_limits<S>::epsilon())
    {
      cut -= tmp;
      trunc = rest * it;
      tmp = S(trunc);
      tmp /= it;
      cut += tmp;
      it *= 10;
      i++;
    }
  return i + 1;
}

template unsigned int	Transform::getPrecision(const int8 &value);
template unsigned int	Transform::getPrecision(const int16 &value);
template unsigned int	Transform::getPrecision(const int32 &value);
template unsigned int	Transform::getPrecision(const float &value);
template unsigned int	Transform::getPrecision(const double &value);

template<typename T>
T Transform::stringToValue(const std::string &str)
{
  T			value(0);
  std::stringstream	strm(str);
  short			inter(0);

  strm.precision(Transform::getStrPrecision(str));
  strm << std::fixed;
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
void Transform::valueToString(const U &value, std::string &dest)
{
  std::ostringstream	strm;

  strm.precision(Transform::getPrecision<U>(value));
  if (sizeof(U) > 1)
    strm << value;
  else
    strm << short(value);
  dest = strm.str();
}

template void Transform::valueToString(const int8 &value, std::string &dest);
template void Transform::valueToString(const int16 &value, std::string &dest);
template void Transform::valueToString(const int32 &value, std::string &dest);
template void Transform::valueToString(const float &value, std::string &dest);
template void Transform::valueToString(const double &value, std::string &dest);
