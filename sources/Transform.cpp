//
// Transform.cpp for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Fri Feb 21 12:45:27 2014 brunne-r
// Last update Sat Mar  1 11:48:51 2014 brunne-r
//

#include "Transform.hh"

template<typename A>
bool			isEqual(A one, A two, int precision)
{
  std::ostringstream	strma, strmb;
  std::string		onecut, twocut;

  strma.precision(precision + 2);
  strmb.precision(precision + 2);
  strma << one;
  onecut = strma.str();
  strmb << two;
  twocut = strmb.str();
  std::cout << onecut << " VS " << twocut << std::endl;
  return (onecut == twocut);
}

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
  std::ostringstream	strm;
  std::string		a,b;
  unsigned int		i;

  i = 1;
  do
    {
      strm.precision(i);
      strm << value;
      a = strm.str();
      strm.str("");
      strm.precision(i + 1);
      strm << value;
      b = strm.str();
      strm.str("");
      std::cout << a << " VS " << b << std::endl;
      i++;
    } while(a.size() != b.size());
  std::cout << i << std::endl;
  return i;
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
