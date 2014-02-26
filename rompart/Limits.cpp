//
// Limits.cpp for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/rompart
// 
// Made by brunne-r
// Login   <brunne-r@epitech.net>
// 
// Started on  Tue Feb 25 11:53:36 2014 brunne-r
// Last update Wed Feb 26 14:38:21 2014 brunne-r
//

#include "AbstractVm.hh"

template<typename T>
void		Limits::check(const std::string &value)
{
  T		ivalue;
  std::string	test;

  ivalue = Transform::stringToValue<T>(value);
  Transform::valueToString<T>(ivalue, test);
  if (test != value)
    {
      if (value[0] == '-')
	std::cerr << "underflow" << std::endl;
      else
	std::cerr << "overflow" << std::endl;
    }
}

template void Limits::check<int8>(const std::string &value);
template void Limits::check<int16>(const std::string &value);
template void Limits::check<int32>(const std::string &value);
template void Limits::check<float>(const std::string &value);
template void Limits::check<double>(const std::string &value);
