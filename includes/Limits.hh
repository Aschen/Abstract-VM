//
// Limits.hh for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/rompart
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Tue Feb 25 11:53:38 2014 brunne-r
// Last update Wed Feb 26 16:29:02 2014 brunne-r
//

#ifndef LIMITS_H
# define LIMITS_H

#include "AbstractVm.hh"
#include "Transform.hh"
#include "Exceptions.hh"

class	Limits
{
public:
    class   Error : public AvmException
    {
    public:
        Error(const std::string error);
        ~Error(void) throw() {}
        const std::string   getMessage(void) const;
    };
public:
  template<typename T>
  static void	check(const std::string &value);
};

#endif /* !LIMITS_H */
