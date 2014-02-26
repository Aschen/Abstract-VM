//
// Transform.cpp for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
// 
// Made by brunne-r
// Login   <brunne-r@epitech.net>
// 
// Started on  Fri Feb 21 12:45:27 2014 brunne-r
// Last update Tue Feb 25 11:22:57 2014 brunne-r
//

#include "AbstractVm.hh"

template<typename T>
T Transform::stringToValue(const std::string &str)
{
  T			value(0);
  std::stringstream	strm(str);
  short			inter(0);

  if (sizeof(T) > 1)
    strm >> value;
  else
    {
      strm >> inter;
      value = T(inter);
    }
  return value;
}

template int8 Transform::stringToValue(const std::string &str);
template int16 Transform::stringToValue(const std::string &str);
template int32 Transform::stringToValue(const std::string &str);
template float Transform::stringToValue(const std::string &str);
template double Transform::stringToValue(const std::string &str);
template long double Transform::stringToValue(const std::string &str);

template<typename U>
void Transform::valueToString(const U &value, std::string &dest)
{
  std::ostringstream	strm;
 
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
