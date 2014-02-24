//
// Transform.hh for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
// 
// Made by brunne-r
// Login   <brunne-r@epitech.net>
// 
// Started on  Fri Feb 21 12:25:03 2014 brunne-r
// Last update Fri Feb 21 14:24:41 2014 brunne-r
//

#ifndef TRANSFORM_H
# define TRANSFORM_H

#include "AbstractVm.hh"

class Transform
{
public:
  template<typename T>
  static T		stringToValue(const std::string &str);
  
  template<typename U>
  static void		valueToString(const U &value, std::string &dest);
};

#endif /* !TRANSFORM_H */
