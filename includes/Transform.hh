//
// Transform.hh for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Fri Feb 21 12:25:03 2014 brunne-r
// Last update Sat Mar  1 10:56:24 2014 brunne-r
//
#include "AbstractVm.hh"

#ifndef TRANSFORM_H
# define TRANSFORM_H

#include <limits>

class Transform
{
public:
  template<typename S>
  static unsigned int	getPrecision(const S &value);

  static unsigned int	getStrPrecision(const std::string &value);

  template<typename T>
  static T		stringToValue(const std::string &str);

  template<typename U>
  static void		valueToString(const U &value, std::string &dest);
};

#endif /* !TRANSFORM_H */
