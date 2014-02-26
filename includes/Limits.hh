//
// Limits.hh for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/rompart
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Tue Feb 25 11:53:38 2014 brunne-r
// Last update Wed Feb 26 14:37:01 2014 brunne-r
//

#ifndef LIMITS_H
# define LIMITS_H

#include "AbstractVm.hh"
#include "Transform.hh"

class	Limits
{
public:
  template<typename T>
  static void	check(const std::string &value);
};

#endif /* !LIMITS_H */
